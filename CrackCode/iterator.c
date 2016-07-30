



BST_iter *
init_iter (Treenode * root) 
{
	BST_iter *new = NULL;
	if (root == NULL) {
		return NULL;
	}

	new = (BST_iter*) malloc (sizeof(BST_iter));

	new->root = root;
	new->stack = newstack();

	while (root) {
		push (new->stack, root);
		root = root->left;
	}

	return new;
}


iter_next (BST_iter *iter, Treenode **next_node)
{
	if (iter == NULL) 
		return NULL;

	if (isEmpty(iter->stack))
		return -1;

	ret = pop(iter->stack);

	tmp = ret->right;
	while (tmp) {
			push (iter->stack, tmp);
			tmp = tmp->left;
		}
	}

	*next_node = ret;
	return;
}





