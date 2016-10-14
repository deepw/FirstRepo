
#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
	int *harr;
	int size;
} Heap;

void 
init_heap (Heap **h, int size) 
{
	if (!h || !size) return;
	Heap *tmp = malloc (sizeof(Heap));
	tmp->harr = malloc (size*sizeof(int));
	tmp->size = size;
	*h = tmp;
	return;
}

void
AddHeap (Heap *h, int data, int index) {
	if (!h || index >= h->size) return;
	h->harr[index] = data;
	return;
}

void 
MinHeapify (Heap *h, int index) {
	int l, r, tmp, min;
	if (!h || index >= h->size) return;
	l = 2*index + 1;
	r = 2*index + 2;

	min = index;
	if (l < h->size && h->harr[l] < h->harr[index]) {
		min = l;
	}
	if (r < h->size && h->harr[r] < h->harr[min]) {
		min = r;
	}
	if (min != index) {
		tmp = h->harr[min];
		h->harr[min] = h->harr[index];
		h->harr[index] = tmp;
		MinHeapify (h, min);
	}
	return;
}


void
MinHeap (Heap *h)
{
	if (!h) return;
	int i = (h->size/2) + 1;
	for (; i>=0; i--) {
		MinHeapify (h, i);
	}
	return;
}

int 
Heapmin (Heap *h, int *val) {
	if (!h) return -1;
	*val = h->harr[0];
	return 0;
}

void 
ReplaceMin (Heap *h, int data) {
	if (!h) return;
	h->harr[0] = data;
}

void
printHeap (Heap *h) {
	int i =0;
	for (i=0; i<h->size; i++) {
		printf ("%d\t", h->harr[i]);
	}
	printf ("\n");
}

void
klargest (int arr[], int n, int k) 
{
	if (n <= 0 || k <= 0 || n < k ) return;
	int i = 0, min = 0;
	Heap *h = NULL;
	init_heap (&h, k);
	for (i=0; i<k; i++) {
		AddHeap (h, arr[i], i);
	}
	MinHeap (h);

	for (; i<n; i++) {
		Heapmin (h, &min);
		if (arr[i] > min) {
			ReplaceMin (h, arr[i]);
			MinHeapify (h, 0);
		}
	}

	printHeap (h);
	return;
}

int main ()
{
	int arr[] = {2, 5, 7, 1, 8, 10, 14, 17, 20, 25, 40, 2, 3, 5, 200};
	klargest (arr, sizeof(arr)/sizeof(arr[0]), 15);
	return 0;
}

		
