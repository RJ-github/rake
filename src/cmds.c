#include "../headers/cmds.h"
#include <stdio.h>
#include <sys/stat.h>

void create_file(const char *dir_name) {
    FILE *fptr;
    char file_path[256];

    snprintf(file_path, sizeof(file_path), "%s/main.c", dir_name);

    fptr = fopen(file_path, "w");

    if (fptr == NULL) {
        perror("Error opening file\n");
        return;
    }

    const char *content = "#include <stdio.h>\n\nint main() {\n    printf(\"Hello, world!\\n\");\n    return 0;\n}\n";
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
		create_file(name);
		printf("project created successfully\n");
	}
}
