/* There is one way of using a map from current list to the new list nodes. Create this map in the first walk of the list. 
 * then walk the list again and using the map adjust the next and random pointers of the new list.
 * The method used here removes the need of a map by just keeping the nodes attached to the current nodes. 
 * In the second walk it adjusts the random pointers. 
 * In the third walk seperates the two lists out.
 */ 
#include <stdio.h>

typedef struct Node {
	struct Node *next;
	struct Node *random;
	int data;
} Node;

int 
clone (Node *root, Node **newroot) 
{
	Node *new = NULL;
	Node *curr = root;
	while (curr) {

		new = newnode (curr->data);
		new->next = curr->next;
		curr->next = new;

		curr = new->next;
	}

	curr = root;
	while (curr) {
		curr->next->random = curr->random->next;
		curr= curr->next->next;
	}
	
	curr = root;
	*newroot = cur->next;
	currnew = *newroot;
	while (curr) {
		curr = curr->next->next;
		currnew->next = currnew->next->next;
		curr = curr->next;
	}
	return 0;
}


