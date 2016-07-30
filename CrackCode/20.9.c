/* 
 * 20.9 Numbers are randomly generated and passed to a method. Write a program to find and maintain the median value as new values are generated.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
median (int a) {
	static int median = 0;
	return median;
}

int
main () {
	int a=0;
	do {
		printf ("\nnext number=?:");
		scanf ("%d", &a);
		printf ("\nMedian = %d.\n", median(a)); 
	} while (a != -1);
	return 0;
}

