#include<stdio.h>

int
max (int a, int b) {
        if (a>b)
                return a;
        else
                return b;
}

int maxp = 0;

int main () {
	int N = 6;
	int arr[] = {10, 7, 5, 8, 11, 9};
	int i =0, j=0;

	for (i=0; i<N-1; i++) {
		for (j=i+1; j<N; j++) {
				maxp = max(maxp, arr[j]-arr[i]);
		}
	}
	printf ("Max profit=%d.\n", maxp);
	return 0;
}
