#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int findKthLargest(int* nums, int numsSize, int k) {
    
    int pivot = 0, i = 0, temp=0, new_pivot=0, max=0, count=0, ij=0;
    pivot = rand()%numsSize;
    i=0;
    max = numsSize;

    do {
	    srand(time(NULL));
    printf ("pivot=%d\n", pivot);
    for (; i<max; i++) {
        if ((i<pivot && *(nums+i) > *(nums+pivot)) || (i>pivot && *(nums+i) < *(nums+pivot))) {
            temp = *(nums+i);
            *(nums+i) = *(nums+pivot);
            *(nums+pivot) = temp;
        }
    }
    if (k == numsSize-pivot) {
        return *(nums+pivot);
    } else if (k < numsSize-pivot) {
	i=pivot;
        new_pivot = pivot + (rand()%(numsSize-pivot));
        if (new_pivot == pivot) {
            pivot = pivot+1;
        } else {
            pivot = new_pivot;
        }
        max = numsSize;
    } else {
	max = pivot;
        pivot = rand()%pivot;
        i = 0;
    }
    printf ("Array now:\n");
    for (ij=0;ij<numsSize;ij++) {
	    printf ("%d,", *(nums+ij));
    }

    } while (count++<10);
    return -1;    
}

int main () {
    //int arr[]={3,2,3,1,2,4,5,5,6};
    int arr[]={7,6,5,4,3,2,1};
    int k = 2;
    printf ("\n%d largest is %d\n", k, findKthLargest(arr, sizeof(arr)/sizeof(arr[0]), k));
    return 0;
}
