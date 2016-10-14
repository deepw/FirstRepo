/* LRU Cache */

#include <stdio.h>

typedef struct listnode {
	struct listnode *left;
	struct listnode *right;
	int pagenumber;
} listnode;

typedef struct Queue {
	listnode *head;
	listnode *tail;
	int capacity;
	int size;
} Queue;

int hash[MAX];


void 
Enqueue (Queue *q, listnode *node) 
{
	listnode *tmp = NULL;
	if (q->size == q->capacity) {
		/* remove the tail element first */
		tmp = q->tail; 
		q->tail = tail->left;
		free (tmp);
		q->size--;
	}

	if (q->head == NULL) {
		q->head = node;
		q->tail = node;
	} else {
		node->right = q->head;
		q->head->left = node;
		
		q->head = node;
	}
	q->size++;
	return;
}




int refer_page (int pagenumber, int hash[], Queue *q)
{

	listnode *node = hash[pagenumber];

	if (node) {
		/* Page was found in the hash. Move the page to the top */

		if (q->head == node) {
			/* already in front nothing to do */
		} else if (q->tail == node) {
			/* remove this node from tail and put it in the front */
			tail = tail->left;
			node->right = q->head;
			q->head->left = node;
			q->head = node;
		} else {
			node->left->right = node->right;
			node->right->left = node->left;

			node->right = q->head;
			q->head->left = node;
			q->head = node;
		}
	} else {
		node = newlistnode(pagenumber);
		Enqueue (node, q);
		hash[pagenumber] = node;
	}
	return 0;
}









