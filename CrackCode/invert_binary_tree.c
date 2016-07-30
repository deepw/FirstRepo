/* 
 * Given a binary tree, invert the binary tree and return it. 
Look at the example for more details.

Example : 
Given binary tree

     1
   /   \
  2     3
 / \   / \
4   5 6   7
invert and return

     1
   /   \
  3     2
 / \   / \
7   6 5   4
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
	printf ("%d\t", root->value);
	inorder_binary_tree (root->left);
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

void 
invert_binary_tree(struct Node *root) 
{
	struct Node *tmp = NULL;
	if (NULL == root) 
		return;
	tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	invert_binary_tree (root->left);
	invert_binary_tree (root->right);
	return;
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
	preorder_binary_tree (root);
	printf ("\n");
	invert_binary_tree (root);
	preorder_binary_tree (root);
	printf ("\n");

}

