#include <stdio.h>


int subarray(int *arr, int s, int n, int *start, int *end)
{
	int i = 0, j = 0, curr=0;
	curr = *arr;	
	while (j < n) {
		if (curr == s) {
			*start = i;
			*end = j;
			return 0;
		}
		if (curr < s) {
			j++;
		 	curr += *(arr+j);
		} else {
			if (i >= j ) {
				j++;
			} else {
				curr -= *(arr+i);
			} 
			i++;
		}
	}
	return 1;
}

int main () 
{
	int arr[] = {1, 4, 20, 3, 10, 5};
	int arr2[] = {1, 4, 0, 5, -3, 10, 5};
	int arr3[] = {1, 4};

	int s=0, e=0;

	if (!subarray(arr, 33, sizeof(arr)/sizeof(arr[0]), &s, &e)) {
		printf ("Sum found between indexes %d and %d\n", s, e);
	} else {
		printf ("No subarray found\n");
	}

	if (!subarray(arr2, 2, sizeof(arr2)/sizeof(arr2[0]), &s, &e)) {
		printf ("Sum found between indexes %d and %d\n", s, e);
	} else {
		printf ("No subarray found\n");
	}

	if (!subarray(arr3, 0, sizeof(arr3)/sizeof(arr3[0]), &s, &e)) {
		printf ("Sum found between indexes %d and %d\n", s, e);
	} else {
		printf ("No subarray found\n");
	}

	return 0;
}




