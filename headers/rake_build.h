#ifndef RAKE_BUILD_H
#define RAKE_BUILD_H

#include "flags_list.h"

typedef enum {
	GCC,
	CLANG,
	MSVC,
	UNKNOWN
} Compiler;

typedef struct{
	Compiler compiler;
	Flag_Node *flags;
} Compile_Command;

void build();

#endif
