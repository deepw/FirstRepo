/* 
 *  Bubble Sort: 
 *  Start at the beginning of an array and swap the first two elements if the first is bigger than the second. 
 *  Go to the next pair, etc, continuously making sweeps of the array until sorted. O(n^2).
 */
#include <stdio.h>

int arr[30];
int N = 30;

void swap (int *a, int *b) {
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void BubbleSort (int arr[], int N) {
	int i=0, j=0, sorted =1;
	for (i=0;i<N;i++) {
		sorted = 1;
		for (j=0;j<N-i-1;j++) {
			if (arr[j] > arr[j+1]) {
				swap (&arr[j], &arr[j+1]);
				sorted = 0;
			}
		}
		if (sorted)
			return;
	}
}

int main () {
	int i =0, n=0;
	for (i=0;i<N;i++) {
		printf("Enter next number: ");
		scanf ("%d", &arr[i]);
		if (arr[i] == -1) {
			break;
		}
		n++;
	}
	BubbleSort(arr, n);
	for (i=0;i<n;i++) {
		printf ("%d\t", arr[i]);
	}
	return 0;
}
