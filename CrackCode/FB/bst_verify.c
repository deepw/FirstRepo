
int
isBST (Node *root, int min, int max) {
	if (!root) return 1;

	if (root->val >= max || root->val <= min) {
		return 0;
	}

	return (isBST (root->left, min, root->data) && isBST (root->right, root->data, max));
}

int
isBST_inorder (Node *root, Node **prev) 
{
	if (!root) return 1;

	if (!isBST_inorder (root->left, prev)) 
		return 0;

	if (prev && root->data <= prev->data) {
		return 0;
	}
	*prev = root;

	return isBST_inorder (root->right, prev);
}

	
