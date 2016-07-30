
#include <stdio.h>

int div(int nom, int den, int *q, int *r)
{
	int neg = 0;
	*q = 0;
	if (den == 0)
		return -1;
	if (nom == 0)
		return 0;
	if (nom < 0 && den < 0) {
		neg = 0;
	} else if (nom < 0 || den < 0) {
		neg = 1;
	}
	if (nom<0) nom = -nom;//+(2*nom);
	if (den<0) den = -den;//+(2*den);

	while (nom >= den) {
		nom = nom-den;
		*q = *q+1;
	}
	if (neg) {
		*q = -*q;// - (2*(*q));
	}

	*r = nom;
	return 0;
}

int main ()
{
	int q, r;

	div (12, 5, &q, &r); 
	printf ("%d/%d => q=%d r=%d\n", 12, 5, q, r);

	div (12, 3, &q, &r) ;
	printf ("%d/%d => q=%d r=%d\n", 12, 3, q, r);

	div (-12, 3, &q, &r) ;
	printf ("%d/%d => q=%d r=%d\n", -12, 3, q, r);

	div (-12, -3, &q, &r) ;
	printf ("%d/%d => q=%d r=%d\n", -12, -3, q, r);

	return 0;
}
