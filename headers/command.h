#ifndef COMMAND_H
#define COMMAND_H

#include "rake_build.h"
typedef struct command {
	Compiler compiler;
	char flags[20][20];
	char linking[50][10];
	char* target;
} command;

void create_command();

#endif
