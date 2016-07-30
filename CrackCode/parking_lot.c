
#include <stdio.h>


int 
sort (int arr[], int n)
{
	int i, j;
	for (i=0; i<n-1; i++) {
		if (arr[i] != i) {
			
			for (j=i; j<n-1; j++) 
				{
					if (arr[j] == i) {
						arr[n-1] = arr[i];
						arr[i] = arr[j];
						arr[j] = arr[n-1];
					}
				}
		}
	}
	
}
