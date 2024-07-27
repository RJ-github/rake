#include "../headers/cmds.h"
#include <stdio.h>

void new_project(char *name) {
	FILE *fptr;

	fptr = fopen(name, "w");

	if (fptr == NULL) {
		perror("Error opening file");
	}

	fclose(fptr);
	printf("project successfullly created");
}
