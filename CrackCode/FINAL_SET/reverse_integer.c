#include <stdio.h>

double
reverse_integer (int n) 
{
	int i = 0;
	double result = 0;
	while (n>0) {
		result = result*10 + n%10;
		n = n/10;
	}
	return result;
}

int main ()
{
	int n = 587593999;
	printf ("Reverse of %d is %f %lu.\n", n, reverse_integer(n), sizeof(double));
	return 0;
}

