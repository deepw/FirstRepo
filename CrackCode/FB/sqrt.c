#include <stdio.h>

int 
mysqrt (double num) 
{
	int l=1, h=num/2, mid=0;
	int r = 0;

	while (l<h) {
		
		mid = (l+h)/2;

		if (mid*mid == num) {
			return mid;
		} else if (num < mid * mid) {
			h = mid-1;
		} else {
			r = mid;
			l = mid+1;
		}
	}
	return r;
}

int main () {
	double n = 101;
	printf ("sqrt of %f is %d.\n", n, mysqrt(n));
	return 0;
}

