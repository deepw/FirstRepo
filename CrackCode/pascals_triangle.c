/*
Given numRows, generate the first numRows of Pascal's triangle. For example, given numRows = 5, the result should be:

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1],
[1,5,10,10,5,1]
]

0 0 1 0 0 
0 1 0 1 0 
0 1 2 1 0
1 3 3 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void print_row (int *cur, int n) 
{
	int i = 0;
	for (i=0; i<n; i++) {
		printf ("%d ", cur[i]);
	}
	printf ("\n");
}

// A O(n^2) time and O(n^2) extra space method for Pascal's Triangle
void printPascal(int n)
{
  int arr[n][n]; // An auxiliary array to store generated pscal triangle values
 
  // Iterate through every line and print integer(s) in it
  for (int line = 0; line < n; line++)
  {
    // Every line has number of integers equal to line number
    for (int i = 0; i <= line; i++)
    {
      // First and last values in every row are 1
      if (line == i || i == 0)
           arr[line][i] = 1;
      else // Other values are sum of values just above and left of above
           arr[line][i] = arr[line-1][i-1] + arr[line-1][i];
      printf("%d ", arr[line][i]);
    }
    printf("\n");
  }
}

/*
void
print_pascal(int N) 
{
	int i=0, j=0, k=0, row=0;
	int *cur_row = malloc (sizeof(int)*(N*N));

	memset (cur_row, 0, sizeof(*cur_row)*N);
	for (i=1, i<=N ; i++) {
		for (j=0; j<=i; j++) {
			if (i==j || i == 0)
				 = 1;
			else
				cur_row[i] = prev_row[i] + prev_row[i-1];
		}
		print_row (cur_row, N);
		memcpy (prev_row, cur_row, sizeof(*prev_row)*N);
		row++;
	}
}
*/

int main()
{
	print_pascal (5);
	return 0;
}


