/* Given a NxN matrix, rotate it 
 * 1	2	3
 * 4	5	6
 * 7	8	9
 * to
 * 7	4	1
 * 8	5	2
 * 9	8	3	
 */

#include <stdio.h>
#include <stdlib.h>


int rotate (int *matrix, int *rotated, int N) {
	int i=0,j=0, k=0,l=0;

	for (i=0, l=N-1; i<N; i++, l--) {
		for (j=0, k=0; j<N; j++, k++) {
			*((rotated+k*N)+l) = *((matrix+i*N)+j);
		}
	}
	return 0;
}

void printarr(int *arr, int N) {
	int i=0,j=0;
	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			printf ("%d\t", *((arr+i*N)+j));
		}
		printf ("\n");
	}
}


int main () {
	int matrix[4][4] = {1, 2, 3, 4,
			   5, 6, 7, 8,
			 9, 10, 11, 12,
			 13, 14, 15, 16
	};
	int rotated[3][3];
	printf ("Original Array:\n");
	printarr ((int*)matrix, 4);
	rotate ((int*)matrix, (int*)rotated, 4);
	printf ("\nRotated Array:\n");
	printarr ((int*)rotated, 4);
	return 0;
}

