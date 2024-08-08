#ifndef FLAGS_LIST_H
#define FLAGS_LIST_H

typedef struct Flag_Node{
	char *flag;
	struct Flag_Node *next;
} Flag_Node;

Flag_Node* create_flag_node(const char *flag);
void add_flag(Flag_Node **head, const char *flag);
void remove_flag(Flag_Node **head, const char *flag);
void free_flags_list(Flag_Node *head);

#endif
