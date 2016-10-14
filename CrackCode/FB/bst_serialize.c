
#include <stdio.h>

void
serialize_preorder (Node *root, int arr[], int *pos)
{
	if (root == NULL)
		return;

	arr[*pos] = root->data;
	*pos++;
	serialize_preorder (root->left, arr, pos);
	serialize_preorder (root->right, arr, pos);
	return;
}

void
deserialize_bst (int arr[], int *preindex, int size, int min, int max)
{
	Node *node = NULL;
	if (*preindex < size) {
		if (arr[*preindex] < max && arr[*preindex] > min) {
			node = newnode (arr[*preindex]);
			*preindex++;
			node->left = deserialize_bst (arr, preindex, size, min, node->data);
			node->right = deserialize_bst (arr, preindex, size, node->data, max);
		}
	}
	return node;
}



