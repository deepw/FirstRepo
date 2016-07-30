#include <stdio.h>
#include <stdlib.h>

#define INT_MAX (1<<sizeof(int)-1)
int max (int a, int b)
{
	if (a>b)
		return a;
	return b;
}
int min (int a, int b)
{
	if (a<b)
		return a;
	return b;
}

int stock (int arr[], int N)
{
	int i = 0;
	int max_gain = 0; //1<<sizeof(int);
	int min_price = 0;

	min_price = arr[0];
	for (i=1; i<N; i++) {
		max_gain = max (max_gain, arr[i]-min_price);
		min_price = min (min_price, arr[i]);
	}
	return max_gain;
}

int main ()
{
	int prices[] = {15, 6, 3, 2, 8, 10, 3, 2, 5};
	printf ("Max gains = %d.\n", stock (prices, sizeof(prices)/sizeof(prices[0])));
	return 0;
}
