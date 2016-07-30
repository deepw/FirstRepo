/* 
 * 20.11 Imagine you have a square matrix, where each cell is filled with either black or white. Design an algorithm to find the maximum subsquare such that all four borders are filled with black pixels.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int 
black_border (int r, int c, int n, int N, int arr[5][5]) {

	int i=0, j=0, k=0;

	if (r+n > N || c+n > N)
		return 0;

	/* Check two rows */
	for (i=c;i<c+n;i++) {
		if (arr[r][i] != 1 || arr[r+n-1][i] != 1) 
			return 0;
	}
	/* Check two columns */
        for (i=r;i<r+n;i++) {
                if (arr[i][c] != 1 || arr[i][c+n-1] != 1)
                        return 0;
        }
	return 1;
}

int
main () {
	int i=0,j=0,k=0,max=0;
	int N = 5;
	int arr[5][5] = {0, 1, 1, 1, 1, 
		         1, 1, 0, 1, 1, 
		         1, 1, 1, 1, 1, 
		         1, 1, 1, 1, 1, 
		         1, 1, 1, 1, 0};
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			for (k=2;k<N;k++) {
				if (black_border (i, j, k, 5, arr)) {
					printf ("Found one at a[%d][%d] %d\n", i, j, k);
					if (k>max)
						max = k;
				}
			}
		}
	}
	printf ("The max sized square is of N=%d.\n", max);
	return 0;
}

