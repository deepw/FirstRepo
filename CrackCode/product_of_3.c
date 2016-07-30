#include <stdio.h>

int max(int a, int b)
{
    if (a>b)
        return a;
    return b;
}

int product(int a[], int N)
{
	printf ("N=%d.\n", N);
	return max(a[N-1]*a[0]*a[1], a[N-1]*a[N-2]*a[N-3]);
}

int main () 
{
    int arr[] = {-13,-5,6,7,10};
    printf ("product=%d.\n", product(arr, sizeof(arr)/sizeof(arr[0])));
}
