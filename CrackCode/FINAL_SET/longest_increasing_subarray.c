#include <stdio.h>

int 
longest_increasing (int arr[], int n)
{
	int i = 0, len = 1, maxlen = 1;

	for (i=1; i<n; i++) {
		if (arr[i] > arr[i-1]) {
			len++;
			if (len > maxlen)
				maxlen = len;
		} else {
			len = 1;
		}
	}

	return maxlen;
}

int main ()
{
	int arr[] = {10, 9, 4, 5, 9, 11, 14, 15, 6, 7, 8};

	printf ("Longest length = %d.\n", longest_increasing (arr, sizeof(arr)/sizeof(arr[0])));
	return 0;
}


