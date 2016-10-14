/*
 * There is two dimensional array where each sub array (row) is sorted, i.e.
 *
 * [[1 1000 2000]
 * [20 10001 5000]
 * [55 1002 222222]]
 *
 * Find a minimum range contain a number from each row. For above array it should be (1000-1002) range.  
 *
 */

typedef struct heap {
	int *harr;
	int size;
	int max;
} heap;

typdef struct range {
	int start;
	int end;
} range;

typedef struct heapnode {
	int value;
	int array;
	int index;
} heapnode;

UpdateMinRange (range min_range, heap *h) {

	heapnode p = getmin (h);
	if (h->max - p->value < min_range.end - min_range.start) {
		min_range.start = p->value;
		min_range.end = h->max;
	}
	return;
}

range
get_min_range (int n, int k, int input[][n]) 
{
	int i = 0;
	heap *h;
	heapnode *new;
	init_heap (&h, k);
	for (i=0; i<k; i++) {
		new = newheapnode ();
		new->value = input[i][0];
		new->array = i;
		new->index = 1;
		AddHeap (new, i);
	}

	MinHeap (h);

	while (1) {

		update_min_range (min_range, h);

		node = getMin();
		node->index++;
		if (node->index == n) {
			return min_range;
		} else {
			node->value = input[node->array][node->index];
		}
		MinHeapify (h);
	}

