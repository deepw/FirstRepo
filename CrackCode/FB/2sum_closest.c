

#include <stdio.h>

int 
pair_closest (int arr[], int n, int target, int *x, int *y) 
{
	qsort (arr, 0, n-1);
	int min_diff = MAX;
	int s = 0;
	int e = n-1;

	while (s < e) {
	       sum = arr[s] + arr[e];

	       if (abs(target - sum) < abs(min_diff)) {
		       min_diff = target-sum;
		       *x = s; *y = e;
		}

	       if (sum < target) {
		       s++;
		} else if (sum > target) {
			e--;
		} else {
			return;
		}
	 }
}

