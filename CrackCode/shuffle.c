#include <stdio.h>

int 
shuffle (int arr[], int n)
{
	int i = 0;

	for (i=n-1; i > 0; i--) {
		r = rand() % (i+1);
		swap (&arr[r], &arr[r]);
	}
	return;
}

		

