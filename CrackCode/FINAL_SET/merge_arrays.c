#include <stdio.h>

int
merge (int arr1[], int arr2[], int m, int n)
{
	int i=0, j=0, k=0;

	for (i=n-1, j=m+n-1; i>=0; i--, j--) {
		arr2[j] = arr2[i];
	}

	i=0; j=m; k=0;
	while (i<m && j<m+n) {
		if (arr1[i] < arr2[j]) {
			arr2[k] = arr1[i];
			i++;
		} else {
			arr2[k] = arr2[j];
			j++;
		}
		k++;
	}

	while (i<m) {
		arr2[k++] = arr1[i++];
	}

	while (j<m+n) {
		arr2[k++] = arr2[j++];
	}

	return 0;
}

int printarr (int arr[], int n) {
	int i = 0;
	for (i=0; i<n; i++) {
		printf ("%d\t", arr[i]);
	}
	printf ("\n");
	return 0;
}

int main () {
	int arr1[] = {1, 4, 6, 8, 10, 14};
	int arr2[] = {5, 7, 9, 0, 0, 0, 0, 0, 0};

	printarr (arr1, 6);
	printarr (arr2, 3);
	merge (arr1, arr2, 6, 3);
	printarr (arr2, 9);

	return 0;
}


