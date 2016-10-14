#include <stdio.h>

int max (int a, int b)
{
	if (a>b)
		return a;
	return b;
}

#define MAX 1000

int 
largest_subarry (int arr[], int n)
{
	int i = 0;
	int maxsum = 0;
	int sum = 0;
	for (i=0; i<n; i++) {
		sum = sum + arr[i];
		maxsum = max (maxsum, sum);
		if (sum < 0)
			sum = 0;
	}
	return maxsum;
}

/*Driver program to test maxSubArraySum*/
int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = largest_subarry(a, n);
    printf ("%d.\n", max_sum);
    return 0;
}
