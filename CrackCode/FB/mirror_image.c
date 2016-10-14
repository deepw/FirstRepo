#include <stdio.h>

int mirror (Treenode *root1, Treenode *root2) {
	if (!root1 && !root2) return 1;

	if (!root1 || !root2) return 0;

	return (root1->val == root2->val && mirror (root1->left, root2->right) && mirrot (root1->right, root2->left));
}

