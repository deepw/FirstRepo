
#include <stdio.h>

void swap (int *a, int *b) 
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int dutchflag (int arr[], int n) 
{
	int start = 0, mid = 0, end = n-1;

	while (mid <= end) {
		if (arr[mid] == 0) {
			swap (&arr[mid], &arr[start]);
			start++;
			mid++;
		} else if (arr[mid] == 1) {
			mid++;
		} else {
			swap (&arr[mid], &arr[end]);
			end--;
		}
	}
	printf ("Fixed array:");
	for (start=0; start<n; start++) {
		printf ("%d\t", arr[start]);
	}
	printf ("\n");
	return 0;
}

int 
main () {
	int arr[] = {2, 1, 0, 2, 1, 0, 2, 1, 0, 2, 1, 1, 1};
	dutchflag (arr, sizeof(arr)/sizeof(arr[0]));
	return 0;
}

