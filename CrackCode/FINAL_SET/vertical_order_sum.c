#include <stdio.h>

int 
vertical_sum (Treenode *root, List *head)
{
	head->value += root->data;

	if (root->left) {
		if (head->prev == NULL) {
			head->prev = newlistnode(0);
			head->prev->next = head;
		}
		vertical_sum (root->left, head->prev);
	}
	if (root->right) {
		if (head->next == NULL) {
			head->next = newlistnode (0);
			head->next->prev = head;
		}
		vertical_sum (root->right, head->next);
	}
	return ;
}

List *
vert_sum (Treenode *root) {
	List *Head = newlistnode(0);
	vertical_sum (root, Head);

	while (Head->prev) {
		Head = Head->prev;
	}

	return Head;
}

