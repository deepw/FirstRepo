#include <stdio.h>

void swap (int *a, int *b) 
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int 
move (int arr[], int n) 
{
	int i = 0, j = 0;

	for (i=0; i<n; i++) {
		if (arr[i] != 0) {
			if (arr[j] == 0)
				swap (&arr[j], &arr[i]);
			j++;
		}
	}
	for (i=0; i<n; i++)
		printf ("%d ", arr[i]);
	printf ("\n");
	return 0;
}

int main () {
	int arr[] = {1,1,1,0,0,0,9,0,9,0,9,0};
	move (arr, sizeof(arr)/sizeof(arr[0]));
	return 0;
}
