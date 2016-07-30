/*
 * Median of two sorted arrays
 * Question: There are 2 sorted arrays A and B of size n each. Write an algorithm to find the median of the array obtained after merging the above 2 arrays(i.e. array of length 2n). The complexity should be O(log(n))
 */

#include <stdio.h>
#include <stdlib.h>

int max (int a, int b) {
	if (a>b) 
		return a;
	return b;
}

int min (int a, int b) {
	if (a<b) 
		return a;
	return b;
}

float
common_median(int *a1, int start1, int end1, int *a2, int start2, int end2) {

	int m1 = 0, m2= 0;
	int n1 = 0, n2 = 0;
	/* Now 4 elements are left, two on each subarrays */
	if (end1 - start1 == 1) {
		return ((max(*(a1+start1), *(a2+start2))+ min(*(a1+end1), *(a2+end2)))/2);
	}
	n2 = end2-start2;
	n1 = end1-start1;
	if ((n1+1)%2 == 0) {
		m1 = (*(a1+(n1/2)) + *(a1+(n1/2)+1))/2;
		m2 = (*(a2+(n2/2)) + *(a2+(n2/2)+1))/2;
	} else {
		m1 = *(a1+(n1/2));
		m2 = *(a2+(n2/2));
	}
        printf ("m1=%d, m2=%d.\n", m1, m2);
	if (m1 == m2) {
		return m1;
	}

	if (m1 > m2) {
		return common_median (a1, start1, n1/2, a2, 1+(n2/2), end2);
	} else {
		return common_median (a1, 1+(n1/2), end1, a2, start2, n2/2);
	}
}

int
main () {
	int a1[] = {6, 8, 10, 12};
	int a2[] = {5, 10, 11, 15};

	printf ("Common median = %f.\n", common_median (a1, 0, 3, a2, 0, 3));
	return 0;
}

