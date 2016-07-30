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


int rotate_inplace (int *matrix, int *rotated, int N) {
	int i=0,j=0, k=0,l=0, tmp=0;

	do {
		round = 1;
		for (i=0; i <N-round; i++) {
			for (j=0;j<N;j++) {
				tmp = *((matrix + i*N) + j);
				*((matrix + (i)*N) + j) = *((matrix + (round)*N) + j);
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

