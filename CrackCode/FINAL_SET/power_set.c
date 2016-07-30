#include <stdio.h>

int power_set (int arr[], int N) {
	int i = 0, shift = 0;
	for (i=0; i < 1<<N; i++) {
		printf ("{");
		/* print set for this i */
		shift = 0;
		while (i >> shift) {
			if (i >> shift & 0x1) {
				printf ("%d ", arr[shift]);
			}
			shift++;
		}
		printf ("}\n");
	}
	return 0;
}

int main () 
{
	int n[]= {1, 2, 3, 4};
	power_set (n, sizeof(n)/sizeof(n[0]));
	return 0;
}

