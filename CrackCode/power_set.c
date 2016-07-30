#include <stdio.h>

int power_set (int arr[], int N) {
	int i = 0, bit = 0, num = 0;
	for (i=0; i<1<<N; i++) {
		printf ("{");
		/* print set for this i */
		num = i;
		bit = 0;
		while (num > 0) {
			if (num & 0x1) {
				printf ("%d ", arr[bit]);
			}
			num = num>>1;
			bit++;
		}
		printf ("}\n");
	}
	return 0;
}

int main () 
{
	int n[]= {1, 2};
	power_set (n, sizeof(n)/sizeof(n[0]));
	return 0;
}

