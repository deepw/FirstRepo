/*
 * Given a 2-d matrix with each cell contains a character from the alphabet.
 * Given a word, verify if the exist in this matrix. A word is called to exist in a matrix if there is a path from cells to cells in the matrix and this path creates a word that matches the word we're looking for. a cell could move to all vertex-adjacent cells (so there are 8 adjacent cells) and cannot use a cell more than once
 */

#include <stdio.h>

int CheckWordDFS (char *word, int Matrix[m][n], int M, int N, int i, int j, int Visited[m][n], int pos) 
{
        int rows[] = {-1, -1, 0,  0,  1, 1, 1, -1};
        int cols[] = {-1,  0, 1, -1, -1, 1, 0,  1};

	Visited[i][j]=1;
	if (pos == strlen(word)) 
	{
		return true;
	}
		for (c=0; c<8; c++) {
			if (i+rows[c]<M && j+cols[c]<N && (Matrix[i+rows[c]][j+cols[c]] == word[pos]) && !Visited[i+rows[c]][j+cols[c]]) {
				return CheckWordDFS (word, Matrix, M, N, i+rows[c], j+cols[c], Visited, pos+1);
			}
		}
	Visited[i][j] = 0;
	return false;
}


		



findWord (char *word, Matrix[m][n], int M, int N) 
{
	int i, j;

	int rows[] = {-1, -1, 0,  0,  1, 1, 1, -1};
	int cols[] = {-1,  0, 1, -1, -1, 1, 0,  1};

	for (i=0, i<m; i++) {
		for (j=0; j<n; j++) {
			if (Matrix[i][j] == word[0]) {
				int Visited[M][N];
				if (CheckWord (word, Matrix, m, n, i, j, Visited, 1)) {
					return true;
				}
			}
		}
	}
	return false;
}



