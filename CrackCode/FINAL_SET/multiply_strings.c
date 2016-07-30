#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
multiply (int num1[], int m, int num2[], int n, int result[])
{
	int i=0, j=0, k=0;
	int i1=0, i2=0;
	int sum=0, carry=0;

	for (i=m-1; i>=0; i--) {
		i2=0;
		carry=0;
		for (j=n-1; j>=0; j--) {
			sum = (num1[i] * num2[j]) + result[i1+i2] + carry;
			printf ("sum = %d \n", sum);
			result[i1+i2] = sum%10;
			carry = sum/10;
			i2++;
		}
		if (carry)
			result[i1+i2] += carry;
		i1++;
	}

	i=0;
	for (i=0; i<m+n; i++) 
		printf ("%d ", result[i]);
	printf ("\n");
	i=0;
	while (result[i] != 0) 
		i++;
	j=i-1;
	i=0;
	int tmp=0;
	printf ("%d %d", i, j);
	while (i<j) {
		tmp = result[i];
		result[i] = result[j];
		result[j] = tmp;
		i++;j--;
	}

	i=0;
	printf ("Result=\n");
	while (result[i]!=0)
		printf ("%d ", result[i++]);
	printf ("\n");
	return 0;
}

int main ()
{
	int n1[] = {1, 2, 3};
	int n2[] = {4};

	int result[5];

	memset (result, 0, sizeof(result));
	multiply (n1, sizeof(n1)/sizeof(n1[0]), n2, sizeof(n2)/sizeof(n2[0]), result);
	return 0;
}


