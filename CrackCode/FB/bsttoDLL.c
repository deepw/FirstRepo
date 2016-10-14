#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node *left;
	struct Node *right;
	int value;
} Node;	

void
BSTDLLUtil (Node *root, Node **prev, Node **Head) 
{
	if (root->left) {
		BSTDLLUtil (root->left, prev, Head);
	}

	if (*prev == NULL) {
		*Head = root;
	} else {
		(*prev)->right = root;
	}
	root->left = *prev;
	*prev = root;

	if (root->right) {
		BSTDLLUtil (root->right, prev, Head);
	}

	return;
}

/* Function to print Nodes in a given doubly linked list */
void printList(Node *node)
{
    printf ("\n");
    while (node!=NULL)
    {
        printf("%d ", node->value);
        node = node->right;
    }
    printf ("\n");
}

/* Helper function that allocates a new node with the
 *    given data and NULL left and right pointers. */
Node* newNode(int data)
{
	    Node* new_node = malloc (sizeof (Node));
	        new_node->value = data;
		    new_node->left = new_node->right = NULL;
		        return (new_node);
}

void
BSTtoDLL (Node *root, Node **Head) {
	Node *prev = NULL;
	if (root == NULL)
		return;

	BSTDLLUtil (root, &prev, Head);
	return;
}

void
inorder_binary_tree (struct Node *root)
{
        if (NULL == root)
                return;
        printf ("%d\t", root->value);
        inorder_binary_tree (root->left);
        inorder_binary_tree (root->right);
        return;
}

/* Driver program to test above functions*/
int main()
{
    // Let us create the tree shown in above diagram
    Node *root        = newNode(10);
    root->left        = newNode(12);
    root->right       = newNode(15);
    root->left->left  = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);

    inorder_binary_tree (root);
 
    Node *Head = NULL; 
    // Convert to DLL
    BSTtoDLL (root, &Head);

    // Print the converted list
    printList(Head);
 
    return 0;
}
