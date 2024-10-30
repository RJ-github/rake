#include "rake_build.h"
#include "rake_new.h"
#include <dirent.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char** get_src_files() {
	struct dirent *de;
	char** files = NULL;
	int file_count = 0;

	DIR *dr = opendir("../src"); 
	if (dr == NULL) { 
		printf("No src directory found\n"); 
		return NULL; // Return NULL if directory cannot be opened
	} 

	// First pass: Count files
	while ((de = readdir(dr)) != NULL) {
		if (strcmp(de->d_name, ".") != 0 && strcmp(de->d_name, "..") != 0) {
			file_count++;
		}
	}

	// Allocate space for files + 1 for NULL terminator
	files = malloc((file_count + 1) * sizeof(char*));
	if (files == NULL) {
		printf("Could not allocate memory for 'files'\n");
		closedir(dr);
		return NULL;
	}

	// Rewind directory to read file names
	rewinddir(dr);
	int index = 0;

	// Second pass: Store the file names
	while ((de = readdir(dr)) != NULL) {
		if (strcmp(de->d_name, ".") != 0 && strcmp(de->d_name, "..") != 0) {
			files[index] = malloc((strlen(de->d_name) + 1) * sizeof(char));
			if (files[index] == NULL) {
				printf("Memory allocation failed for file name\n");
				// Free previously allocated memory before exiting
				for (int i = 0; i < index; i++) {
					free(files[i]);
				}
				free(files);
				closedir(dr);
				return NULL;
			}
			strcpy(files[index], de->d_name);
			index++;
		}
	}

	// Null-terminate the array of file names
	files[index] = NULL;

	closedir(dr);
	return files;
}

void create_command(Command cmd) {
	if (cmd.compiler == NULL || cmd.target == NULL || cmd.files == NULL) {
		fprintf(stderr, "Invalid command structure\n");
		return;
	}

	size_t buff_len = strlen(cmd.compiler) + 10;

	for(int i = 0; cmd.files[i] != NULL; i++) {
		buff_len += strlen(cmd.files[i]) + 10;
	}

	buff_len += strlen(cmd.target) + 10;

	char* buffer = malloc(buff_len);
	if(buffer == NULL) {
		perror("could not allocate memory\n");
		return;
	}

	snprintf(buffer, buff_len, "%s ", cmd.compiler);

	for(int j = 0; cmd.files[j] != NULL; j++) {
		strncat(buffer, "src/", buff_len - strlen(buffer) - 1);
		strncat(buffer, cmd.files[j], buff_len - strlen(buffer) - 1);
		strncat(buffer, " ", buff_len - strlen(buffer) - 1);
	}

	strncat(buffer, "-o ", buff_len - strlen(buffer) - 1);
	strncat(buffer, cmd.target, buff_len - strlen(buffer) - 1);

	create_file("..", "build.sh", buffer);
	free(buffer);
}








