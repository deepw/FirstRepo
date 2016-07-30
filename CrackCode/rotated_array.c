/* 
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand. (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * Find the minimum element.You may assume no duplicate exists in the array.
 * 6 7 0 1 2 4 5
 * 7 0 1 2 4 5 6 
 * Same as 9.3.c
 */

#include <stdio.h>
#include <stdlib.h>

int findMin(int arr[], int low, int high)
{
    // This condition is needed to handle the case when array is not
    // rotated at all
    if (high < low)  return arr[0];
 
    // If there is only one element left
    if (high == low) return arr[low];
 
    // Find mid
    int mid = low + (high - low)/2; /*(low + high)/2;*/
 
    // Check if element (mid+1) is minimum element. Consider
    // the cases like {3, 4, 5, 1, 2}
    if (mid < high && arr[mid+1] < arr[mid])
       return arr[mid+1];
 
    // Check if mid itself is minimum element
    if (mid > low && arr[mid] < arr[mid - 1])
       return arr[mid];
 
    // Decide whether we need to go to left half or right half
    if (arr[high] > arr[mid])
       return findMin(arr, low, mid-1);
    return findMin(arr, mid+1, high);
}

int search(int arr[], int l, int h, int key) 
{
	int mid = 0;
	if (l>h) {
		return -1;
	}

	mid = l + (h-l)/2;

	if (arr[mid] == key) return mid;

	if (arr[l] < arr[mid-1]) {
		if (arr[l] <= key && arr[mid-1] >= key) {
			return search (arr, l, mid-1, key);
		} else {
			return search (arr, mid+1, h, key);
		}
	} else {
		if (arr[mid+1] <= key && arr[h] >= key) {
			return search (arr, mid+1, h, key);
		} else {
			return search (arr, l, mid-1, key);
		}
	}
}

int main ()
{
	int A[] = {7,0,1,2,4,5,6};
	int B[] = {4,5,6,7,0,1,2};
	int C[] = {6,7,0,1,2,4,5};
	int D[] = {0,1,2,4,5,6,7};
	int E[] = {7,6,5,4,2,1,0};

	printf ("Minimum element = %d\n", search (A, 0, 6, 6));
	printf ("Minimum element = %d\n", search (B, 0, 6, 1));
	printf ("Minimum element = %d\n", search (C, 0, 6, 4));
	printf ("Minimum element = %d\n", search (D, 0, 6, 3));
	printf ("Minimum element = %d\n", search (E, 0, 6, 7));
	return 0;
}
