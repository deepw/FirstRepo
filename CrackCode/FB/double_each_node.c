#include <stdio.h>

void double_nodes (Node *root) 
{
	if (!root) return;

	root->value = root->value*2;
	double_nodes (root->left);
	double_nodes (root->right);

	return;
}

