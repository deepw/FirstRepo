/* 89.	Print all permutations of 3 pair of parens. ()()(), (()()), (())(),,,. etc  */

#include <stdio.h>

void
permute (int n, int result[], int index, int open, int close) 
{
	if (index == 2*n) {
		int i = 0;
		for (i=0;i<2*n;i++) {
			printf ("%c ", result[i]);
		}
		printf ("\n");
		return;
	}

	if (open < n) {
		result[index] = '{';
		permute (n, result, index+1, open+1, close);
	}
	if (close < open) {
		result[index] = '}';
		permute (n, result, index+1, open, close+1);
	}
	return;
}
#define N 3
int main ()
{
	int result[2*N];
	permute (N, result, 0, 0, 0);
	return 0;
}


