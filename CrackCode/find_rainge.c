/*
 * Given a sorted array of integers, find the starting and ending position of a given target value. Your algorithm's runtime complexity must be in the order of O(log n). If the target is not found in the array, return [-1, -1]. For example, given [5, 7, 7, 8, 8, 10] and target value 8, return [3, 4].
 */

#include <stdio.h>

void
find_range (int *arr, int *low, int *high, int target, int start, int end)
{
	if (start > end)
		return;

	int mid = start + (end-start)/2;

	if (arr[start] == arr[end] && arr[start] == target) {
		*low = start;
		*high = end;
		return;
	}
	if (arr[mid] < target) {
		return find_range (arr, low, high, target, mid+1, end);
	} else if (arr[mid] > target) {
		return find_range (arr, low, high, target, start, mid-1);
	} else {
		*low = mid;
		*high = mid;

		while (*low > 0 && arr[*low-1] == arr[mid])
			*low = *low - 1;
		while (*high < end && arr[*high+1] == arr[mid]) 
			*high = *high + 1;
		return;
	}
}

int main () 
{
	int arr[] = {5, 7, 7, 8, 8, 10};
	int low=0, high=0;
	find_range (arr, &low, &high, 8, 0, 5);
	printf ("range of %d is %d->%d\n", 8, low, high);
	return 0;
}


