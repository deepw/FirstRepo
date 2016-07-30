/* move all 0s to the front of an integer array */
#include <stdio.h>

int 
move (int *arr, int n) {
	int i = 0, start = 0, tmp=0;
	for (i=0; i<n; i++) {
		if (arr[i] == 0) {
			if (arr[start] != 0) {
				tmp = arr[start];
				arr[start] = arr[i];
				arr[i] = tmp;
			}
			start++;
		}
	}
	printf ("New array: ");
	for (i=0; i<n; i++) {
		printf ("%d ", arr[i]);
	}
	printf ("\n");
	return n-start;
}

int main ()
{
	int arr1[] = {5, 0, 2, 5, 0};
	int arr2[] = {5, 5, 2, 5, 5};
	int arr3[] = {0, 0, 0, 0, 0};
	printf ("%d.\n", move(arr1, sizeof(arr1)/sizeof(arr1[0])));
	printf ("%d.\n", move(arr2, sizeof(arr2)/sizeof(arr2[0])));
	printf ("%d.\n", move(arr3, sizeof(arr3)/sizeof(arr3[0])));
	return 0;
}

