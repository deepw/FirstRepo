/* 
 * 8.1 Write a method to generate the nth Fibonacci number.
 */

#include <stdio.h>

/* F(n) = F(n-1) + F(n-2) */

int fibonacci_n(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	else 
		return (fibonacci_n (n-1) + fibonacci_n (n-2));
}
	

int main () {
	int n = 0;
	printf ("n=? :");
	scanf ("%d", &n);
	printf ("nth fibonacci = %d.\n", fibonacci_n (n-1));
	return 0;
}
