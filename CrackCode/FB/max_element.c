
#include <stdio.h>

int
find_max (int arr[], int n)
{
	int max = arr[0];
	int max_index = 0;
	int max_index_count = 0;

	for (i=1; i<n; i++) {
		if (arr[i] > max) {
			max = arr[i];
			max_index = i;
			max_index_count = 1;
		} else if (arr[i] == max) {
			max_index_count++;
			if (rand(1) < 1/max_index_count) {
				max_index = i;
			}
		}
	}
	return max_index_count;
}
