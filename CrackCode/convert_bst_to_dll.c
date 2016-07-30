/* 
 * Convert a given Binary Tree to Doubly Linked List | Set 1
 * Given a Binary Tree (Bt), convert it to a Doubly Linked List(DLL). The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (left most node in BT) must be head node of the DLL.
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

void ConvertBinary (struct Node *root, struct Node **list)
{
	static struct Node *prev = NULL;
	if (root->left) {
		ConvertBinary (root->left, list);
	}

	printf ("%d\n", root->value);
	if (*list == NULL) {
		*list = root;
	} else {
		prev->right = root;
		root->left = prev;
	}
	prev = root;

	if (root->right) {
		ConvertBinary (root->right, list);
	}
}

void ConvertBinary2 (struct Node *root, struct Node **prev, struct Node **list)
{
	if (root->left) {
		ConvertBinary2 (root->left, prev, list);
	}

	printf ("%d\n", root->value);
	if (*list == NULL) {
		*list = root;
	} else {
		(*prev)->right = root;
		root->left = (*prev);
	}
	*prev = root;

	if (root->right) {
		ConvertBinary2 (root->right, prev, list);
	}
}

void print_DLL(struct Node *root) 
{
	printf ("Forward: ");
	while (root->right != NULL) {
		printf ("%d\t", root->value);
		root = root->right;
	}
	printf ("%d\t", root->value);
	printf ("\n");
	printf ("Reverse: ");
	while (root != NULL) {
		printf ("%d\t", root->value);
		root = root->left;
	}
	printf ("\n");
}
	
int
main () {
	int tval = 1;
	int successor=-1;
	struct Node *node = NULL;
	struct Node *list = NULL;
	struct Node *root = NULL;
	printf("Enter value, 0 to end:\n");
        scanf("%d", &tval);
        while (tval != 0) {
                node = (struct Node*)calloc(sizeof(struct Node), 1);
                node->value = tval;
		if (root == NULL) {
			root = node;
			root->left = NULL;
		} else {
			Insert (root, node);
		}
		printf("Enter value, 0 to end:\n");
                scanf("%d", &tval);
        }
	printf ("\n");
	inorder_binary_tree (root);
	printf ("\n");
	node = NULL;
	ConvertBinary2 (root, &node, &list);
	print_DLL (list);
	return 0;
}

