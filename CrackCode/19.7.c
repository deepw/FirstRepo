/* 
 * 19.7  You are given an array of integers (both positive and negative). Find the continuous sequence with the largest sum. Return the sum.
 * EXAMPLE
 * Input: {2, -8, 3, -2, 4, -10}
 * Output: 5 (i.e., {3, -2, 4} )
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
MaxContinous(int *arr, int size) {
	int i=0,j=0;
	int max = 0; int sum = 0;
	for (i=0; i<size; i++) {
		sum += arr[i];
		if (sum < 0) {
			sum=0;
		}
		if (sum>max) {
			max=sum;
		}
	}
	return max;
}

int
main () {
	int arr[] = {2, -8, 3, -2, 4, -10};
	printf ("\nMax sum = %d.\n", MaxContinous(arr, sizeof(arr)/sizeof(arr[0])));
	return 0;
}

