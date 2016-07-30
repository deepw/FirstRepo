#include <stdio.h>

int
highest_smaller (int arr[], int l, int h, int n, int target) {
	if (target < arr[0]) 
		return -1;

	if (l>h)
		return -1;

	int mid = l + (h-l)/2;

	if (mid > l && arr[mid] > target && arr[mid-1] <= target) 
		return arr[mid-1];

	if (mid < h && arr[mid] < target && arr[mid+1] > target)
		return arr[mid];

	if (target < arr[mid])
		return highest_smaller (arr, l, mid-1, n, target);
	else
		return highest_smaller (arr, mid+1, h, n, target);
}

int main () {
	int arr[] = {3, 4, 6, 8, 10};
	int n = sizeof(arr)/sizeof(arr[0]);
	int target = 4;
	printf ("Highest number smaller than %d is %d.\n", target, highest_smaller (arr, 0, n-1, n, target));
	return 0;
}

