
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
        struct Node *next;
        int data;
} Node;

Node *newnode (int data) {
        Node *tmp = malloc(sizeof(Node));
        tmp->next = NULL;
        tmp->data = data;
        return tmp;
}

void
push (Node **Head, int data)
{
        Node *new = newnode (data);

        if (*Head == NULL) {
                *Head = new;
        } else {
                new->next = *Head;
                *Head = new;
        }
        return;
}

int pop (Node **Head) 
{
        if (*Head == NULL) return 0;

        Node *tmp = *Head;

        *Head = (*Head)->next;
        return tmp->data;
}

int
isEmpty (Node *Head) {
        return (Head == NULL);
}

void
balance_paranthesis (char *str) 
{
	Node *s = NULL;
	int i = 0, count = 0;

	while (str[i]) {
		if (str[i] == '{') {
			push (&s, '{');
		} else if (str[i] == '}') {
			if (isEmpty (s)) {
				str[i] = '{';
				count++;
			} else {
				pop (&s);
			}
		}
		i++;
	}
	while (!isEmpty (s)) {
		pop (&s);
		str[i++] = '}';
	}
	while (count--) {
		str[i++] = '}';
	}
	str[i] = '\0';
	return;
}


int main ()
{
	char str[20];

	strcpy (str, "}}}");
	printf ("string: %s.\n", str);
	balance_paranthesis (str);
	printf ("After balancing: %s.\n", str);
	return 0;
}
