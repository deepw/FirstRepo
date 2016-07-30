#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char Dict[][10] = {"hello", "this", "is", "a", "dictionary", "igetbd", "isafg"};

int 
isDictWord (char *word) 
{
	int i = 0;
	for (i=0; i<sizeof(Dict)/sizeof(Dict[0]); i++) {
		if (!strcmp (word, Dict[i])) {
			return 1;
		}
	}
	return 0;
}

int 
isSafe (int i, int j, int n) {
	if (i>=0 && i<n && j>=0 && j<n)
		return 1;
	return 0;
}

void
DFS (int n, int Board[][n], int Visited[][n], int i, int j, char *word, int pos) {

	int k=0, x=0, y=0;
	word[pos] = Board[i][j];

	word[pos+1] = '\0';
	if (isDictWord (word)) {
		printf ("%s.\n", word);
	}
	Visited[i][j] = 1;

	/* Check all neighbors */
	int rows[] = {1, 1, 0, -1,  0, -1,  1, -1};
	int cols[] = {1, 0, 1,  0, -1, -1, -1,  1};

	for (k=0; k<8; k++) {
		x=i+rows[k];
		y=j+cols[k];
		if (isSafe(x, y, n) && !Visited[x][y]) {
			DFS (n, Board, Visited, x, y, word, pos+1);
		}
	}

	Visited[i][j] = 0;
	return;
}

void
boggle_board (int n, int Board[][n])
{
	int i=0, j=0;
	char word[n*n+1];

	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			int Visited[n][n];
			memset (Visited, 0, sizeof(Visited));
			DFS (n, Board, Visited, i, j, word, 0);
		}
	}

	return;
}

int main ()
{
	int Board[][3] = {'i', 's', 'a',
		      'd', 'g', 'f',
		      'b', 't', 'e'};
	boggle_board (3, Board);
	return 0;
}

