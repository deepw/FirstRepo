/* 
 * 1.1 Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column is set to 0.
 */

#include <stdio.h>
#include <stdlib.h>

int
SetZero (uint32_t *image, int N) {
	uint32_t *row = NULL;
	uint32_t *column = NULL;
	int i, j;
	row = (uint32_t *)calloc(sizeof(uint32_t)*N, 1);
	column = (uint32_t *)calloc(sizeof(uint32_t)*N, 1);

	/* Store where zeros occur in the original matrix */
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			if (*(image+(i*N)+j) == 0 ) {
				*(row+i) = 1;
				*(column+j) = 1;
			}
		}
	}

	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			if (*(row+i) == 1 || *(column+j) == 1) {
				*(image+(i*N)+j) = 0;
			}
		}
	}

	return 0;
}

int
main () {
        uint32_t *image = NULL;
	int N, count = 1, i, j;
        printf("Enter size of matrix.:");
	scanf("%d", &N);
	image = (uint32_t *)calloc(sizeof(uint32_t)*N*N, 1);
	/* Set the matrix with consecutive integers */
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			*(image+(i*N)+j) = count++;
			if (count%(7) == 0 )
				*(image+(i*N)+j) = 0;
		}
	}

	printf ("Original matrix:\n");
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			printf("%d\t", *(image+(i*N)+j));
		}
		printf("\n");
	}

	SetZero (image, N);
	printf ("New matrix:\n");
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			printf("%d\t", *(image+(i*N)+j));
		}
		printf("\n");
	}
	return 0;
}
