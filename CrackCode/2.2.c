/* 2.2
 * Implement an algorithm to find the nth to last element of a singly linked list.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct NODE {
	int value;
	struct NODE *next;
};

void
PrintList (struct NODE *head) {
	printf ("The list is:\n");
	while (head != NULL) {
		printf("%d->", head->value);
		head = head->next;
	}
	printf("NULL\n");
}

int
FindNLast (int n, struct NODE *head) {
	struct NODE *front, *back;
        front = head; back = head;
	int i = 0;
	while (i < n+1) {
		if (!front)
			return -1;
		front = front->next;
		i++;
	}
	while (front != NULL) {
		front = front->next;
		back = back->next;
	}
	return back->value;
}

int main() {
	struct NODE *node = NULL;
	struct NODE *head = NULL;
	struct NODE *tnode = NULL;
	int tval = -1;

	printf("Enter values for list: 0 to end.\n");

	while (tval != 0) {
		scanf("%d", &tval);
		if (tval == 0)
			break;
		node = (struct NODE*)calloc(sizeof(struct NODE), 1);
		node->value = tval;
		node->next = NULL;
		if (head == NULL) {
			head = node;
		} else {
			tnode = head;
			while (tnode->next != NULL)
				tnode = tnode->next;
			tnode->next = node;
		}
	}
	PrintList(head);
	printf("Find nth from last. n=? ");
	scanf("%d", &tval);
	printf("\n Nth from last=%d.\n", FindNLast(tval, head));
	return 0;
}


