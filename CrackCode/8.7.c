/* 
 * 8.7 Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents) and pennies (1 cent), 
 * write code to calculate the number of ways of representing n cents.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int coins[] = {1, 5, 10, 25};
int kinds = 4;

void print_result (int *result, int n) {
	int i=0;
	for (i=0; i<n; i++) {
		if (result[i] == 0)
			continue;
		printf ("%d\t", result[i]);
	}
	memset (result, 0, n*sizeof(int));
	printf ("\n");
	return;
}

void collect (int n, int *result, int total, int coin, int index) {
	int i=0; 
	if (coin < 0) 
		return;
	if (total == n) {
		print_result (result, n);
		total =0; index=0;
		return;
	}
	if (total + coins[coin] <= n) {
		result[index] = coins[coin];
		collect (n, result, total + coins[coin], coin, index+1);
	} else {
		collect (n, result, total, coin-1, index);
		total = total - result[index];
		index--;
	}
}

int main () {
	int n = 0; int *result;
	printf ("Value=?: ");
	scanf ("%d", &n);
	result = calloc(1, n*sizeof(int));
	collect (n, result, 0, 3, 0);
}
