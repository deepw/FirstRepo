#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node *prev;
	struct Node *next;
	int data;
} Node;

Node *newnode (int data) {
	Node *tmp = malloc(sizeof(Node));
	tmp->next = NULL;
	tmp->prev = NULL;
	tmp->data = data;
	return tmp;
}

void
Insert (Node **Head, int data) 
{
	Node *new = newnode (data);

	if (*Head == NULL) {
		*Head = new;
		new->prev = new;
		new->next = new;
	} else if (new->data < (*Head)->data) {
		new->next = (*Head);
		(*Head)->prev->next = new;
		new->prev = (*Head)->prev;
		(*Head)->prev = new;
		(*Head) = new;
	} else {
		Node *tmp = *Head;
		while (tmp->next != *Head && tmp->next->data < new->data) {
			tmp = tmp->next;
		}
		new->next = tmp->next;
		tmp->next->prev = new;
		new->prev = tmp;
		tmp->next = new;
	}

	return;
}


int 
main () {
	return 0;
}
