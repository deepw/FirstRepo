#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
	struct Node *left;
	struct Node *right;
	int data;
} Node;

void 
print_path (int result[], int n)
{
	int i = 0;
	for (i=0; i<=n; i++) {
		printf ("%d\t", result[i]);
	}
	printf ("\n");
}

int
print_all_paths (Node *root, int result[], int n, int pos)
{
	if (root == NULL) return -1;

	if (pos >= n) 
		return -1;
	result [pos] = root->data;

	if (!root->left && !root->right) {
		save_path (result, pos);
	}

	if (root->left) {
		print_all_paths (root->left, result, n, pos+1);
	}
	if (root->right) {
		print_all_paths (root->right, result, n, pos+1);
	}
	return 0;
}

void 
printstack (Stack *s) 
{
	if (!s) return;
	if (s->next) {
		printstack (s->next);
	}
	printf ("%d\t", s->val);
	return;
}

void
Iterative_print_path_DFS (Treenode *root) 
{
	Stack *s;
	if (!root) return;

	push (&s, root);

	while (!isEmpty(s)) {
		top = seektop (s);

		if (top->left && !top->left->visited) {
			push (&s, top->left);
		} else if (top->right && !top->right->visited) {
			push (&s, top->right);
		} else {
			top->visited = 1;
			printstack (s);
			pop (&s);
		}
	}
	return;
}




/* Helper function that allocates a new node with the
 *    given data and NULL left and right pointers. */
Node* newNode(int data)
{
            Node* new_node = malloc (sizeof (Node));
            new_node->data = data;
            new_node->left = new_node->right = NULL;
            return (new_node);
}


int main()
{
	int result[10];
    // Let us create the tree shown in above diagram
    Node *root        = newNode(10);
    root->left        = newNode(12);
    root->right       = newNode(15);
    root->left->left  = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);

    //print_all_paths (root, result, 10, 0);
    Iterative_print_path_DFS (root) 
    return 0;
}

