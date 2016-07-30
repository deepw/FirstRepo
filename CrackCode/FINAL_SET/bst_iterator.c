#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Treenode {
	struct Treenode *left, *right;
	int data;
} Treenode;

typedef struct Node {
        struct Node *next;
        Treenode *p;
} Node;

Node *
newnode (Treenode *data) {
        Node *tmp = malloc(sizeof(Node));
        tmp->next = NULL;
        tmp->p = data;
        return tmp;
}

void
push (Node **Head, Treenode *data)
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

Treenode *
pop (Node **Head) 
{
        if (*Head == NULL) return 0;

        Node *tmp = *Head;

        *Head = (*Head)->next;
        return tmp->p;
}

int
isEmpty (Node *Head) {
        return (Head == NULL);
}

typedef struct Handle {
	Node *stack;
} Handle;

void
deep_push (Handle *h, Treenode *root)
{
	while (root) {
		push (&h->stack, root);
		root = root->left;
	}
}


Handle *
init_handle (Treenode *root) 
{
	Handle *h = NULL;
	if (!root) return NULL;

	h = malloc (sizeof(Handle));
	h->stack = NULL;

	deep_push (h, root);
	return h;
}


Treenode *
getNext (Handle *h) {
	if (!h || !h->stack) return NULL;

	Treenode *node = pop (&h->stack);
	deep_push (h, node->right);

	return node;
}


int main ()
{
	return 0;
}

