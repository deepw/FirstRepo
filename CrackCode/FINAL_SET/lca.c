#include <stdio.h>

Node *
LCA (Node *root, int a, int b)
{
	if (!root) return NULL;

	if (root->value == a || root->value == b) 
		return root;

	Node *left = LCA (root->left, a, b);
	Node *right = LCA (root->right, a, b);

	if (left && right) {
		return root;
	}

	if (left) {
		return left;
	} else {
		return right;
	}
}


LCA_BST (Node *root, int a, int b) {
	while (root != NULL) {
		if (root->value > a && root->value > b) 
			root = root->left;
		else if (root->value < a && root->value < b)
			root = root->right;
		else
			break;
	}
	return root;
}



