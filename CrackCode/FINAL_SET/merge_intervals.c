#include <stdio.h>

typedef struct Interval {
	int start;
	int end;
} Interval;

int comparefn (Interval a, Interval b) {
	return (a.start > b.start);
}

int max (int a, int b) {
	if (a > b)
		return a;
	return b;
}

typedef int (*compare_function) (Interval a, Interval b);

int sort (Interval arr[], int l, int h, compare_function cmp) {
	return 0;
}

int Merge (Interval arr[], int n)
{
	int index = 0, i=0;
	sort (arr, 0, n-1, comparefn);

	for (i=1; i<n; i++) {
		if (arr[index].end >= arr[i].start) {
			arr[index].end = max (arr[i].end, arr[index].end);
		} else {
			index++;
			arr[index] = arr[i];
		}
	}

	for (i=0; i<=index; i++) {
		printf ("{%d, %d} ", arr[i].start, arr[i].end);
	}
	printf ("\n");
	return 0;
}

int main()
{
    Interval arr[] =  {{1,6}, {2,3}, {4, 5}};//{ {1,4}, {2,4}, {4,7}, {6,8}, {10, 13}, {11, 12} };
    int n = sizeof(arr)/sizeof(arr[0]);
    Merge (arr, n);
    return 0;
}




