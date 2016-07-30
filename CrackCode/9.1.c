/* 
 *  9.1
 *  You are given two sorted arrays, A and B, and A has a large enough buffer at the end to hold B. 
 *  Write a method to merge B into A in sorted order.
 */
#include <stdio.h>

int A[10] = {12,13,15,18,19,20,0,0,0,0};
int B[4] = {1,4,6,27};

void swap (int *a, int *b) {
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void Merge (int A[], int B[]) {
	int i=0, j=0, k=0;
	for (i=9,j=3,k=i-j-1; j>=0 && k>=0; i--) {
		if (A[k] > B[j]) {
			A[i] = A[k];
			k--;
		} else {
			A[i] = B[j];
			j--;
		}
	}
	while (j>=0) {
		A[i--] = B[j--];
	}
	while (k>=0) {
		A[i--] = A[k--];
	}
}

int main () {
	int i =0, n=10;
	Merge(A, B);
	for (i=0;i<10;i++) {
		printf ("%d\t", A[i]);
	}
	return 0;
}
