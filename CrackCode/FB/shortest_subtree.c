

shorted_subtree (Node *root, Node *cur) 
{
	if (!root) return;

	if (cur->left && cur->right) {
		return cur;
	}

	if (cur->left) {
		return shortest_subtree (root, cur->left);
	} else if (root->right) {
		return shortest_subtree (root, cur->right);
	} else {
		return root;
	}
}

