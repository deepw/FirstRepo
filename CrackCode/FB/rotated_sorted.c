#include <stdio.h>


int 
search (int arr[], int l, int h, int target) 
{
	if (l>h) return -1;

	int mid = l + (h-l)/2;

	if (arr[mid] == target)
		return mid

	if (arr[l] <= arr[mid]) {
		if (target >= arr[l] && target <= arr[mid-1]) {
			return search (arr, l, mid-1, target);
		} else {
			return search (arr, mid+1, h, target);
		}
	} else {
		if (target >= arr[mid+1] && target <= arr[h]) {
			return search (arr, mid+1, h, target);
		} else {
			return search (arr, l, mid-1, target);
		}
	}
}

