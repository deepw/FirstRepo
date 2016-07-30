/*
 * Problem
 *
 * Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
 *
 * The program should run in O(1) space complexity and O(nodes) time complexity.
 *
 * Example:
 *
 * Given 1->2->3->4->5->NULL,
 * return 1->3->5->2->4->NULL.
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

void sort_odd_even (struct NODE *Head) 
{
	struct NODE *odd=NULL, *even=NULL, *evenHead=NULL;

	if (!Head || !Head->next) {
		return;
	}

	odd=Head;
	evenHead=Head->next;
	even=evenHead;

	while (odd && even && even->next) {
		odd->next = even->next;
		odd = odd->next;
		if (odd && even) {
			even->next = odd->next;
			even = even->next;
		}
	}

	odd->next = evenHead;
	return;
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
	sort_odd_even (head);
        PrintList(head);
        return 0;
}
