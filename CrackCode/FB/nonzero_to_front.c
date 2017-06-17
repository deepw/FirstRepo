#include <stdio.h>

void swap (int *a, int *b) 
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int 
move (int arr[], int n) 
{
	int i = 0, j = 0;

	for (i=0; i<n; i++) {
		if (arr[i] != 0) {
			if (arr[j] == 0)
				swap (&arr[j], &arr[i]);
			j++;
		}
	}
	return 0;
}

// Simpler implementation, but sure it walks the array more than once. 
int move2 (int arr[], int n) {
  int curr = 0;
  for (int i=0; i < n; i++) {
    if (arr[i] != 0) {
      arr[curr++] = arr[i];
    }
  }
  for (;curr<n; curr++) {
    arr[curr]=0;
  }
  return 0;
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d\t", arr[i]);
  }
  printf ("\n");
}

int main () {
	int arr[] = {0,2,3,0,0,0,9,0,9,0,7,0};
        printArray(arr, sizeof(arr)/sizeof(arr[0]));
	move (arr, sizeof(arr)/sizeof(arr[0]));
        printArray(arr, sizeof(arr)/sizeof(arr[0]));
	move2 (arr, sizeof(arr)/sizeof(arr[0]));
        printArray(arr, sizeof(arr)/sizeof(arr[0]));
	return 0;
}
