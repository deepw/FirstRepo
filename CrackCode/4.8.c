/* 
 * 4.8 You are given a binary tree in which each node contains a value. 
 * Design an algorithm to print all paths which sum up to that value. 
 * Note that it can be any path in the tree - it does not have to start at the root.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
	struct Node *left;
	struct Node *right;
	int checked;
	int value;
};

int vals[100];

typedef struct {
	int top;
	int arr[50];
} Stack;

Stack new;
Stack new2;

int
pop (Stack *this) {
	int temp = -1;
	if (this->top < 0)
		return -1;
	temp = this->arr[this->top--];
	return temp;
}

int
push (Stack *this, int value) {
	if (this->top == 50) 
		return -1; /* no more space available for inserting */
	this->arr[++this->top] = value;
	return 0;
}

void
Insert (struct Node *root, struct Node *temp) {
	if (root->left == NULL && temp->value < root->value) {
			root->left = temp;
	} else if (root->right == NULL && temp->value >= root->value) {
			root->right = temp;
	} else if (temp->value < root->value) {
		printf ("go left\n");
		Insert(root->left, temp);
	} else {
		printf ("go right\n");
		Insert(root->right, temp);
	}
	return;
}

void 
printpaths (int index) {
	int thisint = vals[index];
	int sum=0, i=0, j=0;
	//for (i=0;i<index;i++) printf ("%d ", vals[i]);
	index--;
	while (index >= 1) {
		i = index;
		sum = vals[i] + vals[i-1];
		i--;
		while (i>=0 && sum<=thisint) {
			if (sum == thisint) {
				for (j=i;j<=index-i+1;j++) {
					printf ("%d -> \t", vals[j]);
				}
				printf (" %d\n", sum);
			}
			i--;
			sum += vals[i];
		}
		thisint = vals[index];
		index--;
	}
}

int gindex = 0;

void 
dfs (struct Node *root) {
	if (root == NULL) 
		return;
	vals[gindex++] = root->value;
	printf ("%d\t\n",root->value);
	if (root->left != NULL)
		dfs (root->left);
	if (root->right != NULL)
		dfs (root->right);
	if (root->left == NULL && root->right == NULL) {
		printpaths(gindex);
		gindex = 0;
	}
	return;
}

int
main () {
	int tval = 1;
	struct Node *node = NULL;
	struct Node *root = NULL;
	printf("Enter value, 0 to end:\n");
        scanf("%d", &tval);
        while (tval != 0) {
                node = (struct Node*)calloc(sizeof(struct Node), 1);
                node->value = tval;
		if (root == NULL) {
			root = node;
		} else {
			Insert (root, node);
		}
		printf("Enter value, 0 to end:\n");
                scanf("%d", &tval);
        }
	printf ("\n");
	dfs (root);
	printf ("\n");
}

