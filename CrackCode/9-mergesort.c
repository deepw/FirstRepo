/* 
 *  Merge Sort: 
 *  Sort each pair of elements. Then, sort every four elements by merging every two pairs. 
 *  Then, sort every 8 elements, etc. O(n log n) expected and worst case.
 */
#include <stdio.h>

int arr[30];
int tmp[30];
int N = 30;

void swap (int *a, int *b) {
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void merge (int arr[], int l, int m, int r) {
        int i=0, j=0, k=0;

	printf ("Merge l=%d m=%d r=%d\n", l, m, r);

#if 0
	/* if there are only two entries just sort them */
	if (l == m) {
		if (arr[l] > arr[m]) {
			printf ("Swapping %d and %d\n", arr[l], arr[m]);
			swap (&arr[l], &arr[m]);
		}
		return;
	}
#endif

	/* For bigger sized arrays, merge the two */
	for (i=l,j=m+1,k=0; i<=m && j<=r;) {
		if (arr[i] < arr[j]) {
			tmp[k++] = arr[i++];
		} else {
			tmp[k++] = arr[j++];
		}
	}

	/* Check if either of the list has elements remaining */
	while (i <= m) 
		tmp[k++] = arr[i++];
	while (j <= r)
		tmp[k++] = arr[j++];

	/* Copy tmp back into arr in sorted order */
	for (i=l, k=0; i<=r; i++, k++) {
		printf ("Copy %d at index %d\n", tmp[k], i);
		arr[i] = tmp[k];
	}
	printf ("done\n");

}

void MergeSort (int arr[], int l, int r) {
	int i=0, j=0, m=0;

	if (l == r)
		return;

	m =  l+(r-l)/2; //(l+r)/2;
	MergeSort (arr, l, m);
	MergeSort (arr, m+1, r);
	merge (arr, l, m, r);
}

int main () {
	int i =0, n=0;
	for (i=0;i<N;i++) {
		printf("Enter next number: ");
		scanf ("%d", &arr[i]);
		if (arr[i] == -1) {
			break;
		}
		n++;
	}
        for (i=0;i<n;i++) {
                printf ("%d\t", arr[i]);
        }
	MergeSort (arr, 0, n-1);
	for (i=0;i<n;i++) {
		printf ("%d\t", arr[i]);
	}
	printf ("\n");
	return 0;
}
