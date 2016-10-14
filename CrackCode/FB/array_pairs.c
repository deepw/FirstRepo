#include <stdio.h>

void
all_pairs (int arr[], int n, int len, int result[], int pos)
{
	if (pos == len) {
		printf ("{");
		int i = 0;
		for (i=0; i<len; i++) {
			printf ("%d ", result[i]);
		}
		printf ("}\n");
		return;
	}

	int j=0;
	for (j=pos; j<n; j++) {
		result[pos] = arr[j];
		all_pairs (arr, n, len, result, pos+1);
	}
	return;
}

/* Did this again myself 8/28/2016 */
void
all_pairs_2 (int arr[], int s, int n, int len, int result[], int pos)
{
	if (pos == len) {
		printf ("{");
		int i = 0;
		for (i=0; i<len; i++) {
			printf ("%d ", result[i]);
		}
		printf ("}\n");
		return;
	}

	int j=0;
	for (j=s; j<n; j++) {
		result[pos] = arr[j];
		all_pairs_2 (arr, j+1, n, len, result, pos+1);
	}
	return;
}

/* arr[]  ---> Input Array
   n      ---> Size of input array
   r      ---> Size of a combination to be printed
   index  ---> Current index in data[]
   data[] ---> Temporary array to store current combination
   i      ---> index of current element in arr[]     */
void combinationUtil(int arr[], int n, int r, int index, int data[], int i)
{
    // Current cobination is ready, print it
    if (index == r)
    {
        for (int j=0; j<r; j++)
            printf("%d ",data[j]);
        printf("\n");
        return;
    }
 
    // When no more elements are there to put in data[]
    if (i >= n)
        return;
 
    // current is included, put next at next location
    data[index] = arr[i];
    combinationUtil(arr, n, r, index+1, data, i+1);
 
    // current is excluded, replace it with next (Note that
    // i+1 is passed, but index is not changed)
    combinationUtil(arr, n, r, index, data, i+1);
}

int main () 
{
	int arr[] = {1, 2, 3, 4};
	int n = 3;
	int result[n];
	int index = 0;
	int i = 0;
	all_pairs_2 (arr, 0, sizeof(arr)/sizeof(arr[0]), n, result, 0);
	//combinationUtil(arr, sizeof(arr)/sizeof(arr[0]), n, 0, result, 0);
	//all_pairs (arr, sizeof(arr)/sizeof(arr[0]), n, result, 0);
	return 0;
}
