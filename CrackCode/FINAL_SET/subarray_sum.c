#include <stdio.h>

int 
subarray_sum (int arr[], int n, int target)
{
	int front = 0, back = 0, sum = 0;

	for (front = 0; front < n; front++) 
	{
		while (sum > target && front > back) {
			sum = sum - arr[back];
			back++;
		} 
		if (sum == target) {
			printf ("Found target = %d at %d to %d.\n", target, back, front-1);
			return 1;
		} 
		sum = sum + arr[front];
	}
	return 0;
}

int hash[1000];
#define OFFSET 100

int 
sa (int arr[], int n, int target) 
{
	int i=0, sum=0;

	for (i=0; i<n; i++) 
	{
		sum = sum + arr[i];

		if (sum == target) {
			printf ("Found target at %d and %d.\n", 0, i);
			return 1;
		}	
		if (hash[sum-target+OFFSET]) {
			printf ("Found target at %d and %d.\n", hash[sum-target+OFFSET]+1, i);
			return 1;
		} else {
			hash[sum+OFFSET] = i;
		}
	}
	return 0;
}

int main () 
{
	int arr[] = {9, 14, -1, -11, 15, 9, 3, 2};
	printf ("Subarray with sum: %d.\n", subarray_sum (arr, sizeof(arr)/sizeof(arr[0]), 11));
	printf ("Subarray with sum: %d.\n", sa (arr, sizeof(arr)/sizeof(arr[0]), 11));
	return 0;
}
