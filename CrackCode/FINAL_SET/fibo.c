#include <stdio.h>

int 
fibo (int nth) 
{
	int back=0, back2=0, n=0, i=0;
	if (n==1 || n==2) return 1;
	back = 1;
	back2 = 1;

	for (i=3; i<=nth; i++) {
		n = back + back2;
		printf ("%d.", n);
		back2 = back;
		back = n;
	}

	return n;
}

int main ()
{
	int n = 6;
	printf ("%d.\n", fibo(n));
	return 0;
}

