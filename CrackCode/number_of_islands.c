/*
 * Given a 2-d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3

*/

#include <stdio.h>
#include <string.h>
#define N 5

int marked[N][N];

int include (int arr[][N], int i, int j) 
{
	if (i >= N || j >= N || i < 0 || j < 0 || !arr[i][j] || marked[i][j])
		return 0;
	return 1;
}

void dfs (int arr[][N], int i, int j) {
	
	marked[i][j]=1;

	/* Visit element above */
	if (include (arr, i-1, j)) {
		dfs (arr, i-1, j);
	}

	/* Visit element below */
        if (include (arr, i+1, j)) {
                dfs (arr, i+1, j);
        }

	/* Visit element left */
        if (include (arr, i, j-1)) {
                dfs (arr, i, j-1);
        }

	/* Visit element right */
        if (include (arr, i, j+1)) {
                dfs (arr, i, j+1);
        }

	return ;
}

int count_islands(int arr[N][N]) 
{
	int i=0, j=0;
	int k=0;
	int num_islands = 0;

	memset (marked, 0, sizeof(int)*N*N);
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			if (!marked[i][j] && arr[i][j]) {
				dfs(arr, i, j);
				num_islands++;
			}
		}
	}
	return num_islands;
}

int main () {
	int arr1[N][N] = {1,1,1,1,0,1,1,0,1,0,1,1,0,0,0,0,0,0,0,0};
	int arr2[N][N] = {1,1,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,1,1};
	printf ("Number of islands=%d.\n", count_islands (arr1));
	printf ("Number of islands=%d.\n", count_islands (arr2));
	return 0;
}
