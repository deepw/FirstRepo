/* 
 * Write a function to swap a number in place without temporary variables. 
 */

#include <stdio.h>
#include <stdlib.h>

int
swap (int *a, int *b) {
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
	return 0;
}

int
main () {
        int a=20, b=30;
        printf("Numbers a=%d, b=%d.\n", a, b);
        swap (&a, &b);
        printf("Numbers a=%d, b=%d.\n", a, b);
	return 0;
}
