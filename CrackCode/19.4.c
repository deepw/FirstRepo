/* 
 * 19.4 Write a method which finds the maximum of two numbers. You should not use if- else or any other comparison operator.
 */

#include <stdio.h>
#include <stdlib.h>

int greater (int a, int b) {
	return (a/b ? a : b);
}

int greater2 (int a, int b) {
	int k=0, msb=0, max=0;
	k = a-b;
	msb = (k >> 31) & 0x1; 
	max = a - msb*(a-b);
	return max;
}

int
main () {
	int a,b;
	printf ("\na=?: ");
	scanf("%d", &a);
	printf ("\nb=?: ");
	scanf("%d", &b);
	printf ("\ngreater=%d\n", greater2(a, b));
	return 0;
}

