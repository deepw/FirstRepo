/*
 * 10.	Input a list of array [[1, 2, 3], [1], [1, 2]] return the list of array, each array is a combination of one element in each array.
 * [[1, 1, 1], [1, 1, 2], [2, 1, 1], [2, 1, 2], [3, 1, 1], [3, 1, 2]]
 */

#include <stdio.h>

void comb (int n, int k, int input[n][k], int length[n], int index, int result[n]) 
{
	int i = 0;
	if (index == n) {
		for (i=0; i<n; i++) {
			printf ("%d ", result[i]);
		}
		printf ("\n");
		return;
	}

	
	for (i = 0; i<length[index]; i++) {
		result[index] = input[index][i];
		comb (n, k, input, length, index+1, result);
	}
	return;
}

int main () {
	int input[][3] = {{1,2,3}, {1,0,0}, {1,2,0}};
	int lengths[] = {3, 1, 2};
	int result[3];

	comb (3, 3, input, lengths, 0, result);
	return 0;
}

