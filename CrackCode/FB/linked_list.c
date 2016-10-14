#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node *next;
	int data;
} Node;

Node *newnode (int data) {
	Node *tmp = malloc(sizeof(Node));
	tmp->next = NULL;
	tmp->data = data;
	return tmp;
}

void
Push (int data, Node **Head)
{
	Node *new = newnode (data);

	if (*Head == NULL) {
		*Head = new;
	} else {
		new->next = *Head;
		*Head = new;
	}
	return;
}

int pop (Node **Head) 
{
	if (*Head == NULL) return;

	Node *tmp = *Head;

	*Head = (*Head)->next;
	return tmp->data;
}

int
isEmpty (Node *Head) {
	return (Head == NULL);
}

void
print  (Node *Head) {

	if (Head == NULL) 
		return;

	printf ("%d\t", Head->data);

	print (Head->next);
	return;
}
void
print_reverse (Node *Head) {

	if (Head == NULL) 
		return;

	print_reverse (Head->next);
	printf ("%d\t", Head->data);

	return;
}

int main () 
{
	Node *Head = NULL;
	Push (1, &Head);
	Push (2, &Head);
	Push (3, &Head);

	Node *tmp = Head;
	while (tmp) {
		printf ("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf ("\n");
	print (Head);
	printf ("\n");
	print_reverse (Head);
	printf ("\n");
	return 0;
}
