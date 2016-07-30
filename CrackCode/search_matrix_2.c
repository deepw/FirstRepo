/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

For example, consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.
*/

#include <stdio.h>
int MatrixSearch (int *arr, int R, int C, int target) 
{
	int i=0, j=0, n=0;
	i = R-1, j=0;
	while (i >= 0 && j<C) {
		n = *((arr+i*C)+j);
		if (target > n) {
			j++;
		} else if (target < n) {
			i--;
		} else {
			return 1;
		}
	}
	return 0;
}


int main()
{
        int arr[5][5] = {1,   4,  7, 11, 15, 2,  5,  8, 12, 19, 3,   6,  9, 16, 22, 10, 13, 14, 17, 24, 18, 21, 23, 26, 30};
        printf ("Number %d exists: %d\n", 31, MatrixSearch ((int*)arr, 5, 5, 31));
        return 0;
}

