/* 
 * LeetCode – Inorder Successor in BST (Java)
 *  
 *  Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
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

void
inorder_binary_tree (struct Node *root) 
{
	if (NULL == root) 
		return;
	inorder_binary_tree (root->left);
	printf ("%d\t", root->value);
	inorder_binary_tree (root->right);
	return;
}

void 
preorder_binary_tree (struct Node *root) 
{
	if (NULL == root) 
		return;
	preorder_binary_tree (root->left);
	printf ("%d\t", root->value);
	preorder_binary_tree (root->right);
	return;
}

void find_successor(struct Node *root, int t, int *s) 
{
	static int next = 0;
	if (!root) return;

	find_successor (root->left, t, s);
	if (next) {
		*s = root->value;
		return;
	} else if (root->value == t) {
		next = 1;
	}
	find_successor (root->right, t, s);
	return;
}

int
main () {
	int tval = 1;
	int successor=-1;
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
	inorder_binary_tree (root);
	printf ("\n");
	find_successor (root, 20, &successor) ;
	printf ("Successor=%d.\n", successor);
	return 0;
}

