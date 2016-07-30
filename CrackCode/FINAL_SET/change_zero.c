#include <stdio.h>
#define R 3
#define C 4
/*
 *  You have a matrix of ints, if a row or   column contains a 0, you should make that entire row or column values 0. 
 */

int
set_all (int m, int n, int input[m][n])
{
	int i=0;
	int j=0;
	int rflag = 0, colflag = 0;

	for (i=0; i<m; i++) {
		if (input[i][0] == 0) {
			colflag = 1;
			break;
		}
	}

	for (j=0; j<n; j++) {
		if (input[0][j] == 0) {
			rflag = 1;
			break;
		}
	}

	for (i=1; i<m; i++) {
		for (j=1; j<n; j++) {
			if (input[i][j] == 0) {
				input[0][j] = 0;
				input[i][0] = 0;
			}
		}
	}

	for (i=1; i<m; i++) {
		for (j=1; j<n; j++) {
			if (input[i][0] == 0 || input[0][j] == 0) {
				input[i][j] = 0;
			}
		}
	}

	if (colflag) {
		for (i=0; i<m; i++) {
			input[i][0] = 0;
		}
	}

	if (rflag) {
		for (j=0; j<n; j++) {
			input[0][j] = 0;
		}
	}

	return 0;
}

/* A utility function to print a 2D matrix */
void printMatrix(int mat[R][C])
{
    int i, j;
    for (i = 0; i < R; i++)
    {
        for (j = 0; j < C; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int mat[R][C] = { {1, 1, 0, 1},
                      {1, 1, 1, 1},
                      {1, 1, 0, 0},
    };
 
    printf("Input Matrix \n");
    printMatrix(mat);

    set_all (R, C, mat);
 
 
    printf("Matrix after modification \n");
    printMatrix(mat);
 
    return 0;
}
