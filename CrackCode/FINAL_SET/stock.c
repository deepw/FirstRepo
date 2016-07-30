#include <stdio.h>
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

int 
maxstock (int arr[], int n) {
	int max_gain = 0;
	int min_price = arr[0];

	int i = 0;
	for (i=0; i<n; i++) {
		min_price = min (min_price, arr[i]);
		max_gain = max (max_gain, arr[i]-min_price);
	}
	return max_gain;
}

int main ()
{
        int prices[] = {15, 6, 3, 2, 8, 10, 3, 2, 5};
        printf ("Max gains = %d.\n", maxstock (prices, sizeof(prices)/sizeof(prices[0])));
        return 0;
}
