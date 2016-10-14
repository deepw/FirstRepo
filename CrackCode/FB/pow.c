#include<stdio.h>

int power (int a, int b) 
{
	int i=0, pow=1;
	for (i=0; i<b; i++) {
		pow = pow*a;
	}
	printf ("Power of (%d, %d) = %d.\n", a, b, pow);
	return 0;
}

float
power2(int a, int b) {
	int pow = 1; float fp = 1; int neg = 0;
	if (b == 0)
		return 1;
	if (b < 0) {
		neg = 1;
		b = -b;
	}
	pow = power2 (a, b/2);
	if (b%2) { 
		fp = pow*pow*a;
	} else {
		fp = pow*pow;
	}
	if (neg) return (1/fp);
	return fp;
}

int main () 
{
	int a, b;
	printf ("pow(a,b)\n:");
	printf ("a=?");
	scanf ("%d", &a);
	printf ("b=?");
	scanf ("%d", &b);
	power (a, b);
	printf ("p2 = %f.\n", power2 (a, b));
	return 0;
}

