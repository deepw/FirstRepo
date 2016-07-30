/* 2.1 Write code to remove duplicates from an unsorted linked list. FOLLOW UP
 * How would you solve this problem if a temporary buffer is not allowed?
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

void
DeleteNodeVal(int val, struct NODE **head) {
	struct NODE *temp = *head;
	struct NODE *del, *hold;

	while ((*head)->value == val) {
		del = *head;
		*head = del->next;
		free(del);
	}
	hold = temp = *head;
	while (temp && temp->next) {
		temp = hold->next;
		while (temp->value == val) {
			del = temp;
			temp = del->next;
			free (del);
		}
		hold->next = temp;
		hold = temp;
	}
	return ;
}

int main() {
	struct NODE *node = NULL;
	struct NODE *head = NULL;
	struct NODE *tnode = NULL;
	int tval = -1;

	printf("Enter values for list: 0 to end.\n");

	while (tval != 0) {
		scanf("%d", &tval);
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
	printf("Delete which node value:");
	scanf("%d", &tval);
	DeleteNodeVal(tval, &head);
	PrintList(head);
	return 0;
}


