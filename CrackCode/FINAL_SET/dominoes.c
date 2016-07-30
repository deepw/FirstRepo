/*
 * You are given a bunch of dominoes. Write a function that determines if any two of those dominoes add up to [6, 6] (e.g. [1,4] + [5, 2]).  
 */
#include <stdio.h>

typedef struct domino 
{
	int left, right;
} domino;

int gethash (domino d) {
	return (d.left*10 + d.right);
}

int 
checkDomino (domino arr[], int n, domino target)
{
	int hash[100];
	int target_hash = gethash(target);
	int hash_cur = 0;
	for (int i = 0; i<n; i++) 
	{
		hash_cur = gethash (arr[i]);
		if (target_hash-hash_cur > 0 && hash[target_hash - hash_cur]) {
			return 1;
		}
		hash[hash_cur] = 1;
	}
	return 0;
}

int 
main () 
{
	domino arr[] = {{1,4}, {5,2}, {3,3}};
	domino target = {6,5};
	printf ("pair exists: %d.\n", checkDomino (arr, 3, target));
	return 0;
}

