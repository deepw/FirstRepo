#include <stdio.h>

int 
isSafe (int i, int j, int n) {
	return (i>=0 && i<n && j>=0 && j<n);
}

void
DFS (int n, int Matrix[][n], int Visited[][n], int i, int j)
{
	int k=0, x, y;

	int rows[] = {0, 1, 1, -1,  0, -1,  1, -1};
	int cols[] = {1, 0, 1,  0, -1, -1, -1,  1};

	Visited[i][j] = 1;
	for (k=0; k<8; k++) {
		x = i+rows[k];
		y = j+cols[k];

		if (isSafe (x, y, n) && !Visited[x][y] && Matrix[x][y] == Matrix[i][j]) {
			DFS (n, Matrix, Visited, x, y);
		}
	}
	return;
}

int
Groups (int n, int Matrix[][n]) {
	int Visited[n][n];
	int i = 0, j = 0, count = 0;

	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			if (!Visited[i][j]) {
				DFS (n, Matrix, Visited, i, j);
				count++;
				printf ("Group number %d. Color=%d.\n", count, Matrix[i][j]);
			}
		}
	}
	return count;
}


int 
main () {
	int M[][5] = {1, 0, 1, 4, 4, 
		      1, 1, 4, 1, 4, 
		      4, 1, 4, 1, 4,
		      1, 4, 4, 4, 1, 
		      1, 4, 4, 4, 1};
	printf ("Groups: %d.\n", Groups(5, M));
	return 0;
}

