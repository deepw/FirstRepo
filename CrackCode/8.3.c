/*
 * 8.3 Write a method to compute all permutations of a string.
 * Copied solution from http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
	char temp;
	//printf ("swap %c and %c\n", *x, *y);
	temp = *x;
	*x = *y;
	*y = temp;
}

/* Function to print permutations of string
This function takes three parameters:
1. String
2. Starting index of the string
3. Ending index of the string. */
void permute(char *a, int l, int r)
{
int i;
if (l == r)
	printf("%s\n", a);
else
{
	for (i = l; i <= r; i++)
	{
		swap((a+l), (a+i));
		permute(a, l+1, r);
		swap((a+l), (a+i)); //backtrack
	}
}
}

/* Driver program to test above functions */
int main()
{
	char str[] = "ABC";
	int n = strlen(str);
	permute(str, 0, n-1);
	//printf ("%s\n", str);
	return 0;
}

