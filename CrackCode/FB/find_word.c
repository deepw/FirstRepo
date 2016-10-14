/* 
 * Given a 2-d matrix with each cell contains a character from the alphabet. Given a word, verify if the exist in this matrix. A word is called to exist in a matrix if there is a path from cells to cells in the matrix and this path creates a word that matches the word we're looking for. a cell could move to all vertex-adjacent cells (so there are 8 adjacent cells) and cannot use a cell more than once
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isSafe (int x, int y, int n) {
	if (x>=0 && x<n && y>=0 && y<n) 
		return 1;
	return 0;
}

int 
DFS (int n, int Matrix[][n], int Visited[][n], char *Word, int pos, int len, int i, int j) 
{
	int k = 0;
	Visited[i][j] = 1;

	if (pos == len) {
		return 1;
	}

	int rows[] = {0, 1, 1, -1, -1,  1, -1,  0};
	int cols[] = {1, 0, 1,  1, -1, -1,  0, -1};

	for (k=0; k<8; k++) {
		int x = i + rows[k];
		int y = j + cols[k];
		if (isSafe (x, y, n) && !Visited[x][y] && Matrix[x][y] == Word[pos]) {
			return (DFS (n, Matrix, Visited, Word, pos+1, len, x, y)) ;
		}
	}
	Visited[i][j] = 0;
	return 0;
}
 

int
WordCheck (int n, int Matrix[][n], char *Word)
{
	int len = 0, i=0, j=0, found = 0;
	if (!Word) return 0;
	
	len = strlen (Word);

	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			int Visited[n][n];
			memset (Visited, 0, sizeof(Visited));
			if (Matrix[i][j] == Word[0]) {
				found = DFS (n, Matrix, Visited, Word, 1, len, i, j);
			}
			if (found) 
				return 1;
		}
	}

	return 0;
}

int main ()
{
	int Matrix[][3] = {'t', 'o', 'p',
		           'h', 'w', 'e',
		           'c', 'e', 'a'};

	char Word[] = "thwce";
	printf ("Find word %s = %d.\n", Word, WordCheck (3, Matrix, Word));

	return 0;
}

