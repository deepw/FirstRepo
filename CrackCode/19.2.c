/* 
 * Write a function to swap a number in place without temporary variables. 
 */

#include <stdio.h>
#include <stdlib.h>

int winner (int matrix[3][3]) {
	int i=0, j=0, sum=0;
	/* Check all r ws */
	for (i=0; i<3; i++) {
		sum = 0;
		for (j=0; j<3; j++) {
			sum += matrix[i][j];
		}
		if (sum == 0)
			return 0;
		if (sum == 3)
			return 1;
	}
        /* Check all cols*/
        for (i=0; i<3; i++) {
                sum = 0;
                for (j=0; j<3; j++) {
                        sum += matrix[j][i];
                }
                if (sum == 0)
                        return 0;
                if (sum == 3)
                        return 1;
        }
        /* Check all diags */
        sum = 0;
        for (i=0, j=0; i<3; i++, j++) {
		sum += matrix[i][j];
        }
        if (sum == 0)
                return 0;
        if (sum == 3)
                return 1;
	sum = 0;
        for (i=0, j=2; i<3; i++, j--) {
                sum += matrix[i][j];
        }
        if (sum == 0)
                return 0;
        if (sum == 3)
                return 1;

	return -1;
}


int
main () {
	int matrix[3][3] = { 0, 0, 1,
			     1, 1, 1,
			     1, 1, 0};
	printf ("\n Winner=%d\n", winner (matrix));
	return 0;
}

