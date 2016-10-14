#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100000

typedef struct HeapNode {
	int data;
	int array;
	int index;
} HeapNode;

typedef struct Heap {
	HeapNode **harr;
	int size;
} Heap;


void
MinHeapify (Heap *h, int i) {
	int left=2*i+1, right=2*i+2, min=0; 
	HeapNode *tmp;
	
	min = i;
	if (left < h->size && h->harr[left]->data < h->harr[i]->data) {
		min = left;
	}
	if (right < h->size && h->harr[right]->data < h->harr[min]->data) {
		min = right;
	}

	if (min != i) {
		tmp = h->harr[i];
		h->harr[i] = h->harr[min];
		h->harr[min] = tmp;
		MinHeapify (h, min);
	}
	return;
}

void 
init_heap (Heap** h, int k) {
	Heap *tmp = malloc (sizeof(Heap));
	tmp->harr = malloc (k*sizeof (HeapNode*));
	tmp->size = k;
	*h = tmp;
	return;
}

void
HeapAdd (Heap *h, HeapNode *node, int index) 
{
	h->harr[index] = node;
	return;
}

void
MinHeap (Heap* h) {
	int i =0 ;

	i = (h->size - 1)/2;
	while (i>=0) {
		MinHeapify (h, i);
		i--;
	}
	return;
}

HeapNode * 
getMin (Heap *h) {
	return h->harr[0];
}

HeapNode *
newnode () {
	HeapNode *tmp;
	tmp = malloc (sizeof(HeapNode));
	return tmp;
}

int Merge (int arrays[][4], int k, int n, int result[]) 
{
	int i=0, j=0, r=0; 
	HeapNode *node = NULL, *minnode = NULL;
	Heap *h = NULL;
	init_heap (&h, k);

	for (i=0; i<k; i++) {
		node = newnode();
		node->data = arrays[i][0];
		node->array = i;
		node->index = 1;
		HeapAdd (h, node, i);
	}
	MinHeap (h);

	r = 0;

	for (i=0; i<n*k; i++) {
		minnode = getMin (h);

		result[r++] = minnode->data;

		if (minnode->index < n) {
			minnode->data = arrays[minnode->array][minnode->index];
			minnode->index++;
		} else {
			minnode->data = MAX;
		}
		MinHeapify (h, 0);
	}

	return 0;
}

// A utility function to print array elements
void printArray(int arr[], int size)
{
   for (int i=0; i < size; i++)
       printf ("%d->%d\t", i, arr[i]);

   printf ("\n");
}
 
	
// Driver program to test above functions
int main()
{
    // Change n at the top to change number of elements
    // in an array
    int n = 4;
    int arr[3][4] =  {{2, 6, 12, 34},
                     {1, 9, 20, 1000},
                     {23, 34, 90, 2000}};
    int k = sizeof(arr)/sizeof(arr[0]);

    int output[3*4];
 
    Merge (arr, k, n, output);
 
    printArray (output, n*k);
 
    return 0;
}	
