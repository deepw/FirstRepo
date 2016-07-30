#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	struct node *next;
	int val;
} Node;


Node *new_node (int data) 
{
	Node *tmp = malloc(sizeof(Node));
	tmp->val = data;
	tmp->next = NULL;

	return tmp;
}

void
add_list (int data, Node **Head)
{
	if (Head == NULL)
		return;

	printf ("\nAdding %d.\n", data);
	Node *new = new_node (data);
	if (*Head == NULL) {
		*Head = new;
		(*Head)->next = *Head;
		return;
	}

	Node *tmp = *Head;
	if (data > tmp->val) {
		new->next = tmp->next;
		tmp->next = new;
		*Head = new;
	} else {
		/* Handle smallest element */
		tmp = (*Head)->next;
		if (data < tmp->val) {
			(*Head)->next = new;
			new->next = tmp;
			return;
		}
		while (tmp->next->val < data) {
			tmp = tmp->next;
		}
		new->next = tmp->next;
		tmp->next = new;
	}
	return;
}

void
walk_list (Node *Head) 
{
	Node *tmp = Head;
	printf ("List -> ");
	if (Head->next == Head) {
		printf ("%d", Head->val);
	} 
	else {
		tmp = Head->next;
		do {
			printf ("%d ", tmp->val);
			tmp = tmp->next;
		} while (tmp != Head->next);
	}
	printf ("\n");
	return;
}


int main ()
{
	Node *Head = NULL;
	add_list (10, &Head);
	walk_list (Head);
	add_list (11, &Head);
	walk_list (Head);
	add_list (2, &Head);
	walk_list (Head);
	add_list (1, &Head);
	walk_list (Head);
	add_list (15, &Head);
	walk_list (Head);
	add_list (5, &Head);
	walk_list (Head);
	add_list (6, &Head);
	walk_list (Head);
	return 0;
}


