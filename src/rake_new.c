#include "../headers/rake_new.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

// Helper function to create the full path
void create_full_path(
		char *dest, size_t size, const char *dir_name, const char *sub_dir
		) {
    snprintf(dest, size, "%s/%s", dir_name, sub_dir);
}

void create_file(
		const char *dir_name, const char *file_name, const char *content
		) {
    FILE *fptr;
    char file_path[256];

    snprintf(file_path, sizeof(file_path), "%s/%s", dir_name, file_name);

    fptr = fopen(file_path, "w");

    if (fptr == NULL) {
        perror("Error opening file\n");
        return;
    }

    fprintf(fptr, "%s", content);

    fclose(fptr);
    printf("File '%s' created successfully.\n", file_path);
}

int create_dir(const char *name) {
	if (mkdir(name, 0755) == 0) {
		printf("directory created successfully\n");
		return 0;
	} else {
		perror("Error creating directory\n");
		return 1;
	}
}

void new_project(const char *name) {
	if (create_dir(name) == 0) {
		char src_dir[256];
		create_full_path(src_dir, sizeof(src_dir), name, "src");

		if(create_dir(src_dir) == 0) {
			create_file(src_dir, "main.c", "#include <stdio.h>\n\nint main() {\n    printf(\"Hello, world!\\n\");\n    return 0;\n}\n");
		}


		create_file(name, "build.sh", "gcc main.c -o main");

		char bin_dir[256];
		create_full_path(bin_dir, sizeof(bin_dir), name, "bin");
		create_dir(bin_dir);


		printf("project created successfully\n");
	}
}
