/*
 * Question about working on two lists with integers and add them as we do with normal numbers.
 */


int 
add_lists (Node *Head1, Node *Head2) {
	if (!Head1 && !Head2) {
		return;
	} else if (Head1->next && Head2->next) {
		add_lists (Head1->next, Head2->next);
	} else if (Head1->next) {
		add_lists (Head1->next, Head2);
	} else {
		add_lists (Head1, Head2->next);
	}
	newnode = Head1->val + Head2->val;
}

int add_samesize_lists (Node *Head1, Node *Head2) 
{
	if (Head1 == NULL) 
		return;

	int sum; 

	Node *new = newnode();
	result->next = add_samesize_lists (Head1->next, Head2->next);

	sum = Head1->val + Head2->val + *carry;
	result->data = sum%10;
	carry = sum/10;

	return result;
}

