#include <stdio.h>

int
mirror_images (Treenode *root1, Treenode *root2)
{
	if (root1 == NULL && root2 == NULL) 
		return true;

	if (!root1 || !root2) {
		return false;
	}

	if (root1->val != root2->val) 
		return false;

	return (mirror_images(root1->left, root2->right) && mirror_images(root1->right, root2->left));
}

