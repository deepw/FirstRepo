/*
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has properties:
 *
 * 1) Integers in each row are sorted from left to right. 2) The first integer of each row is greater than the last integer of the previous row.
 *
 * For example, consider the following matrix:
 *
 * [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 *       Given target = 3, return true.
 *
 *       n = R*row + col.
 *
 *       col = n-
 */

#include <stdio.h>

int BinarySearch(int arr[3][4], int target, int R, int C) 
{
	int start=0, end=0, num=0, mid=0, row=0, col=0;
	int n = R*C;

	start=0; end=n-1;

	while (start <= end) {
		mid = start + (end-start)/2;
		row = mid / C;
		col = mid % C;

		num = arr[row][col];
		if (target > num) {
			start=mid+1;
		} else if (target < num) {
			end=mid-1;
		} else {
			return 1;
		}
	}
	return 0;
}

int main() 
{
	int arr[3][4] = {1,3,5,7,10,11,16,20,23,30,34,50};
	printf ("Number %d exists: %d\n", 51, BinarySearch(arr, 51, 3, 4));
	return 0;
}




