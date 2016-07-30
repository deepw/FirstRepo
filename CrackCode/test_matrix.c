#include <stdio.h>

void
print_array(int arr[M]) {
	int i=0;
	for (i=0; i<M; i++) {
		printf ("%d", arr[i]);
	}
}

int main ()
{
	int arr[]={1,2,3,4,5};
	print_array(arr);
	return 0;
}
