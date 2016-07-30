/* 
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values.

For example, given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as [[15,7], [9,20],[3]]
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct NodeBST {
	struct NodeBST *left;
	struct NodeBST *right;
	int value;
};

struct NODE {
	struct Node *next;
	int value;
};


void
InsertBST (struct NodeBST *root, struct NodeBST *temp) {
	if (root->left == NULL && temp->value < root->value) {
			root->left = temp;
	} else if (root->right == NULL && temp->value >= root->value) {
			root->right = temp;
	} else if (temp->value < root->value) {
		printf ("go left\n");
		InsertBST (root->left, temp);
	} else {
		printf ("go right\n");
		InsertBST (root->right, temp);
	}
	return;
}

void
PrintList (struct NODE *head) {
	printf ("The list is:\n");
	while (head != NULL) {
		printf("%d->", head->value);
		head = head->next;
	}
	printf("NULL\n");
}

Iterative_all_paths (struct Node *root) {




}


int main() {
	struct NodeBST *node = NULL;
	struct NodeBST *head = NULL;
	struct NodeBST *tnode = NULL;
	int tval = -1;

	printf("Enter values for list: 0 to end.\n");
	scanf("%d", &tval);
	while (tval != 0) {
                node = (struct NodeNST*)calloc(sizeof(struct NodeBST), 1);
                node->value = tval;
                if (root == NULL) {
                        root = node;
                } else {
                        InsertBST (root, node);
                }
                printf("Enter value, 0 to end:\n");
                scanf("%d", &tval);
        }

	LevelOrder (head);
	return 0;
}


