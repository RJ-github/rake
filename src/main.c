#include "../headers/rake_build.h"
#include "../headers/rake_new.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	if(argc == 1) {
		printf("not enough args\n");
		return 0;
	}

	if(argc > 2) {
		printf("Too much args");
		return 0;
	}

	if (strcmp(argv[1], "new") == 0) {
		char *name = argv[2];
		new_project(name);
	} else if(strcmp(argv[1], "build") == 0) {
		build();
	} else {
		printf("command not found\n");
	}

	return 0;
}
