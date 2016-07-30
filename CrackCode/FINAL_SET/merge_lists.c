#include <stdio.h>



Node *
merge_lists (Node *Head1, Node *Head2) {
	Node *nHead;
	Node tmp; 
	tmp.next = NULL;
	nHead = &tmp;
	
	while (Head1 && Head2) {
		if (Head1->value < Head2->value) {
			tmp.next = Head1;
			tmp = tmp.next;
			Head1 = Head1->next;
		} else {
			tmp.next = Head2;
			tmp = tmp.next;
			Head2 = Head2->next;
		}
	}

	if (Head1) {
		tmp->next = Head1;
	} else if (Head2) {
		tmp->next = Head2;
	}

	return nHead->next;
}


