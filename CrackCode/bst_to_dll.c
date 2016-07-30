



typedef struct node {
	struct node *left;
	struct node *rght;
	int val;
} Node;

Node * BSTtoDLL(Node *root, Node *prev)
{
	if (!root)
       	{
		return NULL;
	}

	if (root->left) {
		Node *left = BSTtoDLL (root->left);

		while (left->right)
			left = left->right;

		left->right = root;
		root->left = left;
	} 

	if (root->right) {
		Node *right = BSTtoDLL (root->right);

		while (right->left)
			right = right->left;

		right->left = root;
		root->right = right;
	}
	return root;
}

/* A lot simpler version using inorder traversal */
void treetoListRec(Node * node, Node ** last, Node **ptrToHead){
        if(node == NULL)
                return;
        /* Go to left most child */
        if(node->left)
                treetoListRec(node->left, last, ptrToHead);
 
        /* If this wasn't the first node being added to list*/  
        if(*last != NULL){
                (*last)->right = node;
        }
         else{
                 *ptrToHead = node; 
         }
        /*make left pointer point to last node, and update the 
          last node to current*/
 
        node->left = *last;
        *last = node;
 
        /* If there is right child, process right child */
        if(node->right)
                treetoListRec(node->right, last, ptrToHead);
 
}

			
