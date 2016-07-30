/* 
 *  9.1
 *  Given a sorted array of n integers that has been rotated an unknown number of times, give an O(log n) algorithm that finds an element in the array. 
 *  You may assume that the array was originally sorted in increasing order.
 */
#include <stdio.h>

int A[12] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};

int Find (int A[], int find, int s, int e) {
	int mid = (s+e)/2;
	if (A[mid] == find)
		return mid;
	if (A[s] == find)
		return s;
	if (A[e] == find)
		return e;

	if (A[s] < A[e]) {
	       if (find < A[mid]) {
	           return Find (A, find, s, mid-1);
		} else {
		   return Find (A, find, mid, e);
		}
	} else {
		if (A[s] < A[mid] && find < A[mid]) {
			return Find (A, find, s, mid-1);
		} else if (A[mid] < A[e] && find < A[e]) {
			return Find (A, find, mid, e);
		} else if (A[s] > A[mid] && find > A[s]) {
			return Find (A, find, s, mid-1);
		} else if (A[mid] < A[e] && find < A[e]) {
			return Find (A, find, mid, e);
		}	
	}
	return -1;
}

int main () {
	int i =0, n=10;
	n = Find (A, 5, 0, 11);
	printf ("%d\n", n);
	return 0;
}
