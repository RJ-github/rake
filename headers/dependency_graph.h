#ifndef DEPENDENCY_GRAPH_H
#define DEPENDENCY_GRAPH_H

typedef struct FileNode {
	char* name;
	int compiled;
	struct FileNode** dependencies;
	int dependencies_len;
} FileNode;

typedef struct DependencyGraph {
	FileNode** dependencies;
	int dependencies_len;
} DependencyGraph;

FileNode* create_file_node(char* name);
void add_dependency(FileNode* file_node, FileNode* dependency);
int is_dependent(FileNode* file1, FileNode* file2);
void free_graph(DependencyGraph* graph);

#endif
