#include<stdio.h>
#include<stdlib.h>
 
 
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
typedef struct node 
{
    int data;
    struct node* left;
    struct node* right;
}node ;
 
int max (int a, int b)
{
	if (a>b) 
		return a;
	return b;
}

int 
max_depth (node *root, int *max_d, node **dnode) {
	int ld=0, rd=0, d=0;
	if (!root) return -1;

	if (!root->left && !root->right) 
		return 0;

	ld = max_depth (root->left, max_d, dnode);
	rd = max_depth (root->right, max_d, dnode);
	
	d = 1 + max (ld, rd);
	if (d > *max_d) {
		*max_d = d;
		*dnode = root;
	}
	return d;
}

int
find_depth (node *root, int depth, int *md, node **dnode) 
{
	if (!root) 
		return 0;

	if (depth > *md) {
		*md = depth;
		*dnode = root;
	}

	if (root->left)
		find_depth (root->left, depth+1, md, dnode);
	if (root->right)
		find_depth (root->right, depth+1, md, dnode);
	return 0;
}




/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newnode(int data) 
{
    struct node* node = (struct node*)
                                malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
   
    return(node);
}
   
int main()
{
    struct node *root = newnode(1);
 
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5); 
  
    struct node *deepest_node = NULL; 
    int max = 0;
    //max_depth (root, &max, &deepest_node);
    find_depth (root, 0, &max, &deepest_node);
    printf("Hight of tree is %d deepest node=%d.\n", max, deepest_node->data);
   
    getchar();
    return 0;
}
