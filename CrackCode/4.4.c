/* 
 * 4.4 Given a binary search tree, design an algorithm which creates a 
 * linked list of all the nodes at each depth (i.e., 
 * if you have a tree with depth D, you’ll have D linked lists). 
 * Given a directed graph, design an algorithm to find out whether 
 * there is a route be-tween two nodes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
	struct Node *left;
	struct Node *right;
	int value;
};


typedef struct {
	int top;
	int arr[50];
} Stack;

Stack new;
Stack new2;

int
pop (Stack *this) {
	int temp = -1;
	if (this->top < 0)
		return -1;
	temp = this->arr[this->top--];
	return temp;
}

int
push (Stack *this, int value) {
	if (this->top == 50) 
		return -1; /* no more space available for inserting */
	this->arr[++this->top] = value;
	return 0;
}

int 
Enqueue (int value) {
       return push(&new, value);
}

int 
DeQueue () {
	int temp = -1, rvalue = -1;
	/* Move all items from new to new2 */
	temp = pop (&new);
	while (temp != -1) {
		push (&new2, temp);
		temp = pop(&new);
	}
	rvalue = pop(&new2);
	/* Move everything back to new */
	temp = pop (&new2);
	while (temp != -1) {
		push (&new, temp);
		temp = pop(&new2);
	}
	return rvalue;
}

void
Insert (struct Node *root, struct Node *temp) {
	if (root->left == NULL && temp->value < root->value) {
			root->left = temp;
	} else if (root->right == NULL && temp->value >= root->value) {
			root->right = temp;
	} else if (temp->value < root->value) {
		printf ("go left\n");
		Insert(root->left, temp);
	} else {
		printf ("go right\n");
		Insert(root->right, temp);
	}
	return;
}

int s_on_path = 0;

/* Using DFS for finding a path */
void
bfs (struct Node *root) {
	struct Node * temp = root;
	Enqueue(root->value);
	while (tempval != NULL) {
		tval = Dequeue();
		printf ("%d\t", tval);
		Enqueue()

}


int
main () {
	int tval = 1;
	struct Node *node = NULL;
	struct Node *root = NULL;
	printf("Enter value, 0 to end:\n");
        scanf("%d", &tval);
        while (tval != 0) {
                node = (struct Node*)calloc(sizeof(struct Node), 1);
                node->value = tval;
		if (root == NULL) {
			root = node;
		} else {
			Insert (root, node);
		}
		printf("Enter value, 0 to end:\n");
                scanf("%d", &tval);
        }
	printf ("\n");
	isPath (root, 2, 5);
	printf ("\n");
}

