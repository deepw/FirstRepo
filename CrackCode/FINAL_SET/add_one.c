
#include <stdio.h>

void
add_one (int arr[], int n)
{
	int i = n-1, sum=0, carry=1;

	while (i > 0  && carry) {
		sum = arr[i] + carry;
		arr[i] = sum%10;
		carry = sum/10;
		i--;
	}
	if (carry) 
		arr[0] = 1;
	printf ("new number: ");
	for (i=0; i<n; i++) 
		printf ("%d ", arr[i]);
	printf ("\n");
	return;
}

int main () {
	int arr[] = {0, 9, 9, 9};
	add_one (arr, sizeof(arr)/sizeof(arr[0]));
}

