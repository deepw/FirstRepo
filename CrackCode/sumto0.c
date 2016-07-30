/*  You are given an array of numbers, and you want to find   3 numbers that sum to 0 and output those 3 numbers. 
 *  You can use each number multiple times. So if you are given the array [-1, 1, 2], you would output [-1, -1, 2] because -1 -1 +2=0 
 *  https://www.glassdoor.co.uk/Interview/You-and--039-re-given-an-array-of-numbers-and-you-want-to-find-3-numbers-that-sum-to-0-and-output-those-3-numbers-You-can-use-QTN_1075206.htm
 *
*/

#include <stdio.h>

#define MIN 100 /* Assuming all numbers are greater than -100, so the number can be used as index directly */
int hash[9999]; /* Some max hash table size */


int 
find3Numbers(int A[], int arr_size, int sum)
{
    int l, r;
 
    /* Sort the elements */
    //quickSort(A, 0, arr_size-1);
 
    /* Now fix the first element one by one and find the
       other two elements */
    for (int i = 0; i < arr_size - 2; i++)
    {
        // To find the other two elements, start two index variables
        // from two corners of the array and move them toward each
        // other
        l = i; // index of the first element in the remaining elements
        r = arr_size-1; // index of the last element
        while (l < r)
        {
            if( A[i] + A[l] + A[r] == sum)
            {
                printf("Triplet is %d, %d, %d\n", A[i], A[l], A[r]);
                return 1;
            }
            else if (A[i] + A[l] + A[r] < sum)
                l++;
            else // A[i] + A[l] + A[r] > sum
                r--;
        }
    }
 
    // If we reach here, then no triplet was found
    return 0;
}
 
int sumtozero (int arr[], int n ) 
{
	int i = 0, j = 0, target = 0;
	for (i=0; i<n ; i++) {
		target = -arr[i];
		for (j=0; j <n; j++) {
			if (arr[j] == 0) {
				printf ("Found the sum at %d, %d and %d.\n", j, j, j);
				return 1;
			}
			if (hash[target-arr[j]+MIN]) {
				printf ("Found the sum at %d, %d and %d.\n", i, j, hash[target-arr[j]+MIN]-1);
				return 1;
			}
			hash[arr[j]+MIN] = j+1;
		}
	}
	printf ("Not found.\n");
	return 0;
}


int main ()
{
	int arr[] = {-1, 1, 2};
	sumtozero(arr, sizeof(arr)/sizeof(arr[0]));
	find3Numbers (arr, sizeof(arr)/sizeof(arr[0]), 0);
	return 0;
}

