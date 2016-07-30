/* 
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order. You may assume no duplicates in the array.
 *
 * Here are few examples.
 * [1,3,5,6], 5 -> 2
 * [1,3,5,6], 2 -> 1
 * [1,3,5,6], 7 -> 4
 * [1,3,5,6], 0 -> 0
 */

#include <stdio.h>

int binary_search(int *arr, int match, int start, int end) 
{
	int middle = (end+start)/2;
	if (start > end) {
		return -1;
	}
	if (*(arr+middle) == match) {
		return middle;
	} else if (*(arr+middle) < match) {
		return binary_search (arr, match, middle+1, end);
	} else {
		return binary_search (arr, match, start, middle-1);
	}
	return -1;
}

int
find_insert_pos (int *arr, int match, int start, int end)
{
	int middle = (end+start)/2;
	if (match < arr[middle]) {
		return middle>start ? find_insert_pos (arr, match,  start, middle-1) : start; 
	} else if (match > arr[middle]) {
		return middle<end ? find_insert_pos (arr, match, middle+1, end) : end+1;
	} else {
		return middle;
	}
}

int main () {

	int arr[] = {1,3,5,6};
	printf ("Result=%d.\n", binary_search (arr, 2, 0, 3));
	printf ("Result=%d.\n", binary_search (arr, 6, 0, 3));
	printf ("Result=%d.\n", find_insert_pos (arr, 2, 0, 3));
	printf ("Result=%d.\n", find_insert_pos (arr, 7, 0, 3));
	return 0;
}



