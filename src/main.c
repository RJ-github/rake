#include "../headers/cmds.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
	printf("%d args\n", argc);
	char *name = argv[2];
	new_project(name);
	return 0;
}
