
#include <stdio.h>

int
3sum (int arr[], int n, int target) {
	int i = 0, j=0, k=0;

	qsort (arr, 0, n-1);

	for (i=0; i<n-2; i++) {
		for (j=i, k=n-1; j<k;) {
			sum = arr[i] + arr[j] + arr[k];
			if (sum == target) {
				printf ("sum found at %d %d %d.\n", i, j, k);
			} else if (sum < target) {
				j++;
			} else {
				k--;
			}
		}
	}
	return 0;
}

