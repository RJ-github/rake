#include "dependency_graph.h"
#include <stdlib.h>

FileNode* create_file_node(char* file_name) {
	FileNode* file_node = malloc(sizeof(FileNode));
	file_node->name = file_name;
	file_node->dependencies = NULL;
	file_node->dependencies_len = 0;
	return file_node;
}

void add_dependency(FileNode* file_node, FileNode* dependency) {
	file_node->dependencies_len++;
	file_node->dependencies = realloc(file_node->dependencies, file_node->dependencies_len * sizeof(FileNode*));
	file_node->dependencies[file_node->dependencies_len - 1] = dependency;
}
