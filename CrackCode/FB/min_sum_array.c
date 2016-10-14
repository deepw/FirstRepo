#include <stdio.h>

int 
minlength (int arr[], int n, int target, int *minlength, int *sindex, int *eindex) 
{
	int i = 0, j = 0, sum = 0;
	*minlength=n+1;

	for (i=0; i<n; i++) {
		sum = sum + arr[i];
		while (sum > target && j<=i) {
			if (i-j+1 < *minlength) {
				*minlength = i-j+1;
				*sindex = j;
				*eindex = i;
			}
			sum = sum-arr[j];
			j++;
		}
	}

	return 0;
}

/* Driver program to test above function */
int main()
{
    int i=0, j=0, min=0;
    int arr1[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    minlength (arr1, n1, x, &min, &i, &j);
    printf ("Minlength = %d from %d to %d.\n", min, i, j);
 
    int arr2[] = {1, 10, 5, 2, 7};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    x  = 9;
    minlength (arr2, n2, x, &min, &i, &j);
    printf ("Minlength = %d from %d to %d.\n", min, i, j);
 
    int arr3[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    x  = 280;
    minlength (arr3, n3, x, &min, &i, &j);
    printf ("Minlength = %d from %d to %d.\n", min, i, j);
 
    return 0;
}



