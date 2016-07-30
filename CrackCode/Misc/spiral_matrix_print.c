/*
 *  Print a given matrix in spiral form
Given a 2D array, print it in spiral form. See the following examples.

Input:
        1    2   3   4
        5    6   7   8
        9   10  11  12
        13  14  15  16
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 


Input:
        1   2   3   4  5   6
        7   8   9  10  11  12
        13  14  15 16  17  18
Output: 
1 2 3 4 5 6 12 18 17 16 15 14 13 7 8 9 10 11
 */
#include <stdio.h>
#define R 4
#define C 4
 
void spiralPrint (int matrix[R][C]) {


    int row = 0, col=C, iter=0, more=1, c=0, r=0 ;

    while (more) {
    row = iter;
    /* Print the top row from remaining rows */
    for (c=iter; c < C-iter; c++) {
        printf ("%d\t", matrix[row][c]);
    }

    col = C-iter-1;
    /* Print last column from remaining columns */
    for (r=iter+1; r < R-iter; r++) {
        printf ("%d\t", matrix[r][col]);
    }

    row = R-iter-1;
    /* Print the last row from remaining rows */
    for (c=C-iter-2 ; c>=iter ; c-- ) {
        printf ("%d\t", matrix[row][c]);
    }

    col = iter;
    /* Print the left column from remaining cols */
    for (r = R-iter-2; r> iter; r--) {
        printf ("%d\t", matrix[r][col]);
    }
    if (iter >= C/2 || iter >= R/2) {
        more = 0; 
    }
    iter++;
    }
    printf ("\n");

}

/* Driver program to test above functions */
int main()
{
	    int a[R][C] = { 1,  2,  3,  4,  5,  6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	     
	        spiralPrint(a);
		    return 0;
}
