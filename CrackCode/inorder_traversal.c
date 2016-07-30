/* 
 * Given a binary tree, print inorder traversal without using recursion. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
	struct Node *left;
	struct Node *right;
	int value;
};

typedef struct {
        int top;
        int arr[50];
} Stack;

Stack new;

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

int
isEmpty(Stack *this) 
{
	return (this->top == 0);
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
inorder_binary_tree (struct Node *root) 
{
	if (NULL == root) 
		return;
	printf ("%d\t", root->value);
	inorder_binary_tree (root->left);
	inorder_binary_tree (root->right);
	return;
}

void 
inorder_iterative (struct Node *root) 
{
}
	
public int kthSmallest(TreeNode root, int k) {
    Stack<TreeNode> stack = new Stack<TreeNode>();
 
    TreeNode p = root;
    int result = 0;
 
    while(!stack.isEmpty() || p!=null){
        if(p!=null){
            stack.push(p);
            p = p.left;
        }else{
            TreeNode t = stack.pop();
            k--;
            if(k==0)
                result = t.val;
            p = t.right;
        }
    }
 
    return result;
}


void 
preorder_binary_tree (struct Node *root) 
{
	if (NULL == root) 
		return;
	preorder_binary_tree (root->left);
	printf ("%d\t", root->value);
	preorder_binary_tree (root->right);
	return;
}

void 
invert_binary_tree(struct Node *root) 
{
	struct Node *tmp = NULL;
	if (NULL == root) 
		return;
	tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	invert_binary_tree (root->left);
	invert_binary_tree (root->right);
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
	preorder_binary_tree (root);
	printf ("\n");
	invert_binary_tree (root);
	preorder_binary_tree (root);
	printf ("\n");

}

