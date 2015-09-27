/* 
 * 1.1 Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
*/

#include <stdio.h>
#include <stdlib.h>

int
Rotate (uint32_t *image, int N) {
	uint32_t temp = 0;
	int i = 0, j = 0, k = 0; 

	while (k < N) {
		for (i=k, j=0; j<k ; j++) {
			temp = *(image+(i*N)+j);
			*(image+(i*N)+j) = *(image+(j*N)+i);
			*(image+(j*N)+i) = temp;
		}
		k++;
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
		}
	}

	printf ("Original matrix:\n");
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			printf("%d\t", *(image+(i*N)+j));
		}
		printf("\n");
	}

	Rotate(image, N);
	printf ("New matrix:\n");
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			printf("%d\t", *(image+(i*N)+j));
		}
		printf("\n");
	}
	return 0;
}
