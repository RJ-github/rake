#include "rake_build.h"
#include <dirent.h>
#include <string.h>
#include <stdio.h>

void build() {
	struct dirent *de;

	char** files;

	DIR *dr = opendir("../src"); 

	if (dr == NULL)
	{ 
		printf("no src directory found\n"); 
	} 

	while ((de = readdir(dr)) != NULL) {
		if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0) {
			continue;
		}
		printf("%s\n", de->d_name); 
	}

	closedir(dr);     
}
