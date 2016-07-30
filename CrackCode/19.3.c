/* 
 * 19.3 Write an algorithm which computes the number of trailing zeros in n factorial.
 */

#include <stdio.h>
#include <stdlib.h>

int count_zeroes(int N) {
        int sum = 0, n = 0;
	while (N > 0) {
		n=N;
		while (n>0 && n%5==0) {
			sum++;
			n=n/5;
		} 
		N--;
	}
	return sum;
}


int
main () {
	int N = 0;
	printf ("N=?: ");
	scanf("%d", &N);
	printf ("\n Trailaing zeroes in %d!=%d\n", N, count_zeroes(N));
	return 0;
}

