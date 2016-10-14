#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max (int a, int b) {
	if (a>b)
		return a;
	return b;
}

void
add_arrays (int num1[], int num2[], int m, int n, int result[]) 
{
	int i = m-1, j = n-1, k =0, sum = 0, carry = 0, n1, n2;

	k = max(m,n);
	memset (result, 0, max(m, n) + 1);
	while (i >= 0 || j >= 0) {
		if (i >= 0)
			n1 = num1[i];
		else 
			n1 = 0;

		if (j >= 0)
			n2 = num2[j];
		else 
			n2 = 0;

		sum = n1 + n2 + carry;
		result[k] = sum%10;
		carry = sum/10;
		i--; j--; k--;
	}

	if (carry) {
		result[k] = 1;
	}

	return;
}

void print (int arr[], int n)
{
	int i = 0;
	for (i=0; i<n; i++) {
		printf ("%d ", arr[i]);
	}
	printf ("\n");
	return;
}

int main () {
	int a[] = {9, 9, 9};
	int b[] = {1};

	int result[4];

	add_arrays (a, b, sizeof(a)/sizeof(a[0]), sizeof(b)/sizeof(b[0]), result);
	print(result, 4);
	return 0;
}



