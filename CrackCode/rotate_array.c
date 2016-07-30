#include <stdio.h>
#include <stdlib.h>

void
rotate_array(int *arr, int n, int size) {
	int i=0,j=0,prev=0,tmp=0, rotation=0;
	while (rotation++ < n) {
		prev = *(arr);
		for (i=0; i<size-1; i++) {
			tmp = *(arr+i+1);
			*(arr+i+1) = prev;
			prev = tmp;
		}
		*arr = prev;
	}
}

int main () {
        int N=8, i=0;
	int arr[]= {0,1,2,3,4,5,6,7};
	for (i=0;i<N;i++) { 
		printf ("%d ", arr[i]);
	}
        printf ("\n");
	rotate_array (arr, 3, N);
        for (i=0;i<N;i++) { 
                printf ("%d ", arr[i]);
        }
        printf ("\n");
        return 0;
}


