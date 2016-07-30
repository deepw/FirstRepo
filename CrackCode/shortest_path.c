/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
*/

#include <stdio.h>

#define m 4
#define n 4

int min (int a, int b) 
{
	if (a<b)
		return a;
	return b;
}

/* Stores path from 0,0 to that node */
int path[m][n];

/* Stores the path itself */
int parent[m][n];
#define UP 1
#define LEFT 2

int short_path_bottom_up(int arr[][n]) 
{
	int i=0, j=0;
	int up=0, left=0;

	path[0][0] = arr[0][0];
	/* Fill the first column */
	for (i=1; i<m; i++) {
		path[i][0] = path[i-1][0] + arr[i][0];
		parent[i][0] = UP;
	}
	/* Fill the first row */
	for (i=1; i<n; i++) {
		path[0][i] = path[0][i-1] + arr[0][i];
		parent[0][i] = LEFT;
	}

	for (i=1; i<m; i++) {
		for (j=1; j<n; j++) {
			up = path[i-1][j];
			left = path[i][j-1];
			if (up < left) {
				parent[i][j] = UP;
				path[i][j] = up + arr[i][j];
			} else {
				parent[i][j] = LEFT;
				path[i][j] = left + arr[i][j];
			}
		}
	}

	i=m-1; j=n-1;
	while (i>0 || j>0) {
		printf ("%d\t", arr[i][j]);
		if (parent[i][j] == UP)
			i--;
		else 
			j--;
	}
	printf ("%d\t", arr[0][0]);

	return (path[m-1][n-1]);
}

int main () 
{
	int arr[m][n] = {1,2,1,3, 4,2,6,5, 3,7,2,5, 7,6,2,4};
	printf ("path is size=%d.\n", short_path_bottom_up(arr));



	return 0;
}
