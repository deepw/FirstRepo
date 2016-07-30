/* 
 * 4.1 Implement a function to check if a tree is balanced. 
 * For the purposes of this question, a balanced tree is defined to be a tree such that 
 * no two leaf nodes differ in distance from the root by more than one.
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

int 
min (int a, int b) {
	if (a<b)
		return a;
	else 
		return b;
}

int 
max (int a, int b) {
	if (a>b)
		return a;
	else 
		return b;
}

int
maxDepth(struct Node *root) {
	if (root == NULL)
		return 0;
	return (max(maxDepth(root->left), maxDepth(root->right)) + 1);
}

int
minDepth(struct Node *root) {
	if (root == NULL)
		return 0;
	return (min(minDepth(root->left), maxDepth(root->right)) + 1);
}

void
InOrder (struct Node *root) {
	if (root == NULL)
		return;
	InOrder(root->left);
	printf ("%d\t", root->value);
	InOrder(root->right);
}

bool 
isBalanced (struct Node *root) {
	return (maxDepth(root)-minDepth(root)<=1);
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
	InOrder(root);
	printf ("\n");
	printf ("max depth = %d\n", maxDepth(root));
	printf ("min depth = %d\n", minDepth(root));
	printf ("is tree Balanced: %s\n", isBalanced(root) ? "yes" : "no");
}

