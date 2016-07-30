#include <stdio.h>

typedef struct Node {
	struct Node *next;
	struct Node *child;
	int data;
} Node;

int Enq();
int Deq();
int init_queue();

/* This uses a queue and walks the list only once. */
void flatten (Node *Head) 
{
	Queue *q;
	Node *curr = NULL;
	if (!Head) return NULL;

	init_queue (&q);

	Enq (&q, Head);

	curr = Head;
	while (curr) {
		while (curr->next != NULL) {
			if (curr->child != NULL) {
				Enq (&q, curr->child);
			}
			curr = curr->next;
		}
		if (curr->next == NULL && curr->child != NULL) {
			Enq (&q, curr->child);
		}
		curr->next = Deq (&q);
		curr = curr->next;
	}
	return;
}

void flatten (Node *Head) 
{
	Queue *q;
	Node *curr = Head;

	init_queue (&q);

	Enq (&q, Head);

	curr = Head;
	while (curr) {
		if (curr->child) 
			Enq (&q, cur->child);
		if (!curr->next && !isEmpty(q))
			curr->next = Deq (&q);
		curr = curr->next;
	}
	return;
}

/* This does not use any extra space but walks the list twice */
void 
flatten2 (Node *Head) 
{
	Node *cur = NULL, *tail = NULL;
	if (Head == NULL) return;
	cur = Head;
	tail = Head;
	while (tail->next)
		tail = tail->next;

	while (cur != tail) {
		if (cur->child != NULL) {
			tail->next = cur->child;
			while (tail->next)
				tail = tail->next;
		}
		cur = cur->next;
	}
	return ;
}

int main () {
	return 0;
}


