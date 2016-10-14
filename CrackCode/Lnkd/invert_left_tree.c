#include <stdio.h>

invert (Node *root, Node **newroot, Node *prev) 
{
	if (root->left == NULL) {
		root->left = root->right;
		root->right = prev;
		*newroot = root;
		return;
	}

	Node * tmp = root->right;
	root->right = prev;
	invert (root->left, newroot, root);
	root->left = tmp;
	return;
}


