#include <stdio.h>

int 
cuberoot (int n) 
{
	int s = 1;
	int f = 1; int mid = 0;
	int neg = 0;
	if (n < 0) {
		neg = 1;
		n = -n;
	}
	int e = n/3;
	 while (s < e) {
		mid = (s+e)/2;

		if (mid*mid*mid == n) {
			 f = mid;
			 break;
		} else if (mid*mid*mid > n) {
			e = mid-1;
		} else {
			f = mid;
			s = mid+1;
		}
	}

 	if (neg)	 
		return -f;
	else
		return f;
}

int main () {
	int n = -9;
	printf ("cuberoot of %d is %d.\n", n, cuberoot(n));
	return 0;
}

