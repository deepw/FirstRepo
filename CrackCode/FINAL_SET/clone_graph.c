#include <stdio.h>

typedef struct Node {
	struct Node *next;
	struct Node *random;
	int data;
} Node;

int 
clone (Node *root, Node **newroot) 
{
	Node *new = NULL;
	Node *curr = root;
	while (curr) {

		new = newnode (curr->data);
		new->next = curr->next;
		curr->next = new;

		curr = new->next;
	}

	curr = root;
	while (curr) {
		curr->next->random = curr->random->next;
		curr= curr->next->next;
	}
	
	curr = root;
	*newroot = cur->next;
	currnew = *newroot;
	while (curr) {
		curr = curr->next->next;
		currnew->next = currnew->next->next;
		curr = curr->next;
	}
	return 0;
}


