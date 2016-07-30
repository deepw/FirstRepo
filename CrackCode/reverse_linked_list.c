/*
 * LeetCode – Reverse Linked List (Java)
 *  
 *  Reverse a singly linked list.
 *  1->2->3->4->NULL
 *  4->3->2->1->NULL
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

void reverse_list(struct NODE **Head) 
{
	struct NODE *node1=NULL, *node2=NULL, *node3=NULL;

	node1=*Head;
	node2=node1->next;
	if (node1->next) node3=node1->next->next;
        node1->next=NULL; 
	while (node3) {
		node2->next=node1;
		node1=node2;
		node2=node3;
		node3=node3->next;
	} 

	node2->next=node1;
	*Head = node2;
	return;
}

void reverse_list_recursive (struct NODE **Head) {






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
        reverse_list (&head);
        PrintList(head);
        return 0;
}
