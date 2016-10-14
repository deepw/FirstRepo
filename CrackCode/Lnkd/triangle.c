#include <stdio.h>

int
find_triangles (int arr[], int n) 
{
	int i = 0, j = 0, k = 0, answer;

	for (i=0; i<n-2; i++) {
		k = i+2;
		for (j=i+1; j<n-1; j++) {
			if (k<n && arr[i] + arr[j] > arr[k]) {
				k++;
			}
			answer += k-j;
		}
	}
	return 0;
}

int
find_triangle (int arr[], int n) 
{
	int i = 0, j = 0, k = 0;

	for (i=0; i<n-2; i++) {
		for (j=i+1; j<n-1; j++) {
			if (arr[i] + arr[j] > arr[j+1]) {
				printf ("Found one triangle with %d %d %d.", arr[i], arr[j], arr[j+1]);
				return 1;
			}
		}
	}
	return 0;
}

int 
main () 
{
	int i = 0;
	int arr[] = {2,3,5,8,10,14,15};
	find_triangle (arr, sizeof(arr)/sizeof(arr[0]));
	return 0;
}

