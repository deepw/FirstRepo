

#include <stdio.h>

int max (int a, int b) {
	if (a>b)
		return a;
	return b;
}

int
knapsack (int *values, int *sizes, int i, int n, int max_size) 
{
	if (i >= n)
		return 0;

	if (sizes[i] > max_size) {
		return knapsack (values, sizes, i+1, n, max_size);
	}

	return max (knapsack (values, sizes, i+1, n, max_size), knapsack (values, sizes, i+1, n, max_size-sizes[i]) + values[i]);
}

int main ()
{
	int values[] = {3, 2, 1, 1, 1, 1};
	int  sizes[] = {2, 3, 3, 3, 3, 1};
        int Size = 4;	
	printf ("Max value = %d\n", knapsack (values, sizes, 0, sizeof(sizes)/sizeof(sizes[0]), Size));
	return 0;
}

