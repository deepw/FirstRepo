#include <stdio.h>
#include <string.h>

int hash[1000];

int
remove_duplicates (int arr[], int n, int *sz) 
{
	int i = 0, j = 0;

	for (i=0; i<n; i++) 
	{
		if (arr[j] != arr[i]) {
			j++;
			arr[j] = arr[i];
		}
	}
	*sz = j+1;
	return 0;
}

int 
remove_duplicates2 (int arr[], int n, int *sz) {
	int i=0, j = 0;
	memset(hash, 0, sizeof(hash));
	for (i=0; i<n; i++) {
		if (!hash[arr[i]]) {
			hash[arr[i]] = 1;
			arr[j] = arr[i];
			j++;
		}
	}
	*sz = j;
	return 0;
}

void print (int *a, int n) 
{
	int i = 0;
	for (i=0; i<n ; i++) {
		printf ("%d\t", a[i]);
	}
	printf ("\n");
}

int main ()
{
	int a1[] = {1,2,2,3,4,5};
	int a2[] = {1,1,1};//,2,2,2,3,3};
	int a3[] = {1,2,3,4,5,6,6};
	int a4[] = {1,2,3,4,5};
	int sz = 0;
	
	print (a1, 6);
	remove_duplicates (a1, 6, &sz);
	printf ("After removing:\n");
	print (a1, sz);
	printf ("\n");

        print (a2, 3);
        remove_duplicates (a2, 3, &sz);
	printf ("After removing:\n");
        print (a2, sz);
	printf ("\n");

        print (a3, 7);
        remove_duplicates (a3, 7, &sz);
	printf ("After removing:\n");
        print (a3, sz);
	printf ("\n");

        print (a4, 5);
        remove_duplicates (a4, 5, &sz);
	printf ("After removing:\n");
        print (a4, sz);
	printf ("\n");

}

