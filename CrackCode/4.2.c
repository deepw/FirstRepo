/* 
 * 4.2 Given a directed graph, design an algorithm to find out whether 
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
isPath(struct Node *root, int s, int d) {
	if (root->left != NULL) {
		if (root->left->value == s) s_on_path = 1;
		isPath(root->left, s, d);
	} 
	if (root->right != NULL) {
		if (root->right->value == s) s_on_path = 1;
		isPath(root->right, s, d);
	}
        if (d == root->value && s_on_path) {
                printf ("Path found from %d to %d.\n", s, d);
        }
        if (s == root->value) s_on_path = 0;
        printf ("%d\t", root->value);
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

