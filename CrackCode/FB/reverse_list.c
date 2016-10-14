


reverse_recursive (Node *cur, Node *prev, Node **Head)
{
	if (cur->next == NULL) {
		*Head = cur;
		cur->next = prev;
		return;
	}

	Node *next = cur->next;
	cur->next = prev;

	reverse_recursive (next, cur, Head);
}

Node *
reverse (Node *Head) 
{
	Node *curr = Head;
	Node *prev = NULL;

	Node *next = NULL;

	while (curr != NULL) {
		next = cur->next;
		cur->next = prev;

		cur = next;
		prev = cur;
	}

	return prev;
}
