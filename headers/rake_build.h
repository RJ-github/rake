#ifndef RAKE_BUILD_H
#define RAKE_BUILD_H

typedef struct Command {
	char* compiler;
	char** files;
	char* target;
} Command;

char** get_src_files();
void create_command(Command cmd);

#endif
