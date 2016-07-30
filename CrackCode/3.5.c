/* 
 * 3.5 Implement a MyQueue class which implements a queue using two stacks.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int top;
	int arr[50];
} Stack;

Stack new;
Stack new2;

int
pop (Stack *this) {
	int temp = -1;
	if (this->top < 0)
		return -1;
	temp = this->arr[this->top--];
	return temp;
}

int
push (Stack *this, int value) {
	if (this->top == 50) 
		return -1; /* no more space available for inserting */
	this->arr[++this->top] = value;
	return 0;
}

int 
Enqueue (int value) {
       return push(&new, value);
}

int 
DeQueue () {
	int temp = -1, rvalue = -1;
	/* Move all items from new to new2 */
	temp = pop (&new);
	while (temp != -1) {
		push (&new2, temp);
		temp = pop(&new);
	}
	rvalue = pop(&new2);
	/* Move everything back to new */
	temp = pop (&new2);
	while (temp != -1) {
		push (&new, temp);
		temp = pop(&new2);
	}
	return rvalue;
}

int
main () {
	new.top = -1;
	new2.top = -1;
	memset (&new.arr, 0, sizeof(new.arr));
	memset (&new2.arr, 0, sizeof(new.arr));
	push(&new, 1);
	push(&new, 2);
	push(&new, 3);
	push(&new, 4);
	push(&new, 5);
	printf ("Popped: %d.\n", pop(&new));
	printf ("Popped: %d.\n", pop(&new));
	printf ("Popped: %d.\n", pop(&new));
	printf ("Popped: %d.\n", pop(&new));
	printf ("Popped: %d.\n", pop(&new));
	printf ("Popped: %d.\n", pop(&new));

	Enqueue(1);
	Enqueue(2);
	Enqueue(3);
	Enqueue(4);
	Enqueue(5);
	
	printf ("Dequeued: %d.\n", DeQueue());
	printf ("Dequeued: %d.\n", DeQueue());
	printf ("Dequeued: %d.\n", DeQueue());
	printf ("Dequeued: %d.\n", DeQueue());
	printf ("Dequeued: %d.\n", DeQueue());
	printf ("Dequeued: %d.\n", DeQueue());
}
