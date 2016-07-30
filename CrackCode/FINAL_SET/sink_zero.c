#include<stdio.h>

int
sink_zero (Node *root) 
{
	if (!root) return;

	sink_zero (node->left);
	sink_zero (node->right);
	sinkify (node);

	return 0;
}

int
sinkify (Node *root) 
{
	if (!root || !root->value != 0)
		return 0;

	if (root->left && root->left->value != 0) {
		swap (&root->value, &root->left->value);
		sinkify (root->left);
	} else if (root->right && root->right->value != 0) {
		swap (&root->value, &root->right->value);
		sinkify (root->right);
	}
	return;
}


