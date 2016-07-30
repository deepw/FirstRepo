#include <stdio.h>

reverse (Node **Head) {

	if (!Head || !*Head)
		return;

	Node *prev = NULL;
	Node *cur = *Head;
	Node *next = NULL;

	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	*Head = prev;
	return;
}

Node *
reverse_recursive (Node *Head, Node *prev) 
{
	Node *tmp = NULL;

	if (Head == NULL)
		return prev;

	tmp = Head->next;

	Head->next = prev;
	prev = Head;

	return reverse_recursive (tmp, prev);
}
