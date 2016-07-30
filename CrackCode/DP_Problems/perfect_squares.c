/*
 * Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
 *
 * For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b)
{
	if (a<b)
		return a;
	return b;
}

int 
min_squares (int n)
{
	int i = 0;
	if (n==0)
		return 0;

	int sub_min = 9999;
	for (i=1; i*i<=n; i++) {
		sub_min = min (sub_min, 1+min_squares(n-(i*i)));
	}
	return sub_min;
}

int min_squares_memoized (int n) 
{
	int DP[n+1];
	int i, j;

	for (i=0; i<=n; i++) {
		DP[i] = 999;
		for (j=1; j*j <= i; j++) {
			if (j*j==i) 
				DP[i] = 1;
			else
				DP[i]= min (DP[i], 1+DP[i-(j*j)]);
		}
	}

	return DP[n];
}

int main ()
{
	int n = 17;
	printf ("Min squares for number %d is %d.\n", n, min_squares(n));
	printf ("Min squares 2 for number %d is %d.\n", n, min_squares_memoized (n));
	return 0;
}

