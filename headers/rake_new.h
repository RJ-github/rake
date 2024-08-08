#ifndef RAKE_NEW_H
#define RAKE_NEW_H

#include <stdio.h>

void create_full_path(
		char *dest, size_t size, const char *dir_name, const char *sub_dir
);
int create_dir(const char *name);
void create_file(
		const char* name, const char *file_name, const char *content
);
void new_project(const char *name);

#endif
