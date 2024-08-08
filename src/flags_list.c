#include "../headers/flags_list.h"
#include <stdlib.h>
#include <string.h>

Flag_Node* create_flag_node(const char *flag) {
	Flag_Node *new_node = (Flag_Node*)malloc(sizeof(Flag_Node));

	new_node->flag = strdup(flag);
	new_node->next = NULL;
	return new_node;
}

void add_flag(Flag_Node **head, const char *flag) {
	Flag_Node *new_node = create_flag_node(flag);

	new_node->next = *head;
	*head = new_node;
}

void remove_flag(Flag_Node **head, const char *flag) {
	Flag_Node *current = *head;
	Flag_Node *previous = NULL;

	while (current != NULL && strcmp(current->flag, flag) != 0) {
		previous = current;
		current = current->next;
	}

	if (current != NULL) {
		if (previous == NULL) {
			*head = current->next;
		} else {
			previous->next = current->next;
		}

		free(current->flag);
		free(current);
	}
}

void free_flags_list(Flag_Node *head) {
	Flag_Node *current = head;
	while (current != NULL) {
		Flag_Node *temp = current;
		current = current->next;
		free(temp->flag);
		free(temp);
	}
}
