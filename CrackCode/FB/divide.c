#include <stdio.h>


void
divide (int n, int d, int *q, int *r) 
{
	int shift = 0, base = 0;

	*q = 0;
	while (n > d) {
		shift = 0;
		while (n > (d << shift)) {
			shift++;
		}
		shift--;
		*q = *q + (1<<shift);
		n = n - (d << shift);
	}
	*r = n;
	return;
}

int main () 
{
	int n = 2003;
	int d = 53;
	int q = 0, r = 0;
	divide (n, d, &q, &r);
	printf ("%d/%d => q=%d r=%d.\n", n, d, q, r);

	return 0;
}




