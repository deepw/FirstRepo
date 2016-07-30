#include <stdio.h>
#include <stdlib.h>

int fibo (int n)
{
	int i=0, res=0;
	int *fn = (int*) malloc(sizeof(int)*(n+1));

	fn[0]=1;
	fn[1]=1;
	for (i=2; i<n+1; i++)
	{
		fn[i] = fn[i-1]+fn[i-2];
	}
	res = fn[n];
	free (fn);
	return res;
}

int fibo_rec(int n)
{
	if (n==0 || n==1)
		return 1;
	return (fibo_rec(n-1) + fibo_rec(n-2));
}

int main () 
{
	int n = 20;
	printf ("nth fibo = %d.\n", fibo(n));
	printf ("nth fibo = %d.\n", fibo_rec(n));
	return 0;
}


