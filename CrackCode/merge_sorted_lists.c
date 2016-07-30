


Node* merge (Node *head1, Node *head2) 
{
	tmp1 = head1;
	tmp2 = head2;

	if (head1->val < head2->val) { 
		new_list_head = head1;
		tmp1 = tmp->next;
	} else {
		new_list_head = head2;
		tmp2 = tmp2->next;
	}

	tmp3 = new_list_head;

	while (tmp1 && tmp2) {
		if (tmp1->val < tmp2->val) {
			tmp3->next = tmp1;
			tmp1 = tmp1->next;
		} else {
			tmp3->next = tmp2;
			tmp2 = tmp2->next;
		}
		tmp3 = tmp3->next;
	}
	if (tmp1) {
		tmp3->next = tmp1;
	}
	if (tmp2) {
		tmp3->next = tmp2;
	}
	return new_list_head;
}






