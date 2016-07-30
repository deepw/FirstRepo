/*
 * Given a matrix in which each row and each column is sorted, write a method to find an element in it.
 */

#include <stdio.h>

int A[4][4] = {2, 8, 9,  11, 
	      5, 13, 35, 36, 
	      7, 17, 37, 39, 
	      9, 19, 38, 40};

void Find (int find, int m, int n) {
	int i=0, j=n-1;
 
	for (; i<m && j>=0; ) {
		printf ("A[%d][%d]=%d\n", i, j, A[i][j]);
		if (A[i][j] == find) {
			printf ("Found %d at [%d][%d].\n", find, i, j);
			return;
		}
		if (find > A[i][j]) {
			i++;
		} else {
			j--;
		}
	}
	printf ("Not found.\n");
	return;
}

int 
main () {
	int n = -1;
	printf ("Find number?");
	scanf ("%d", &n);
	Find (n, 4, 4);
	return 0;
}
