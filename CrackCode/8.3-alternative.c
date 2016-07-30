/*
 * 8.3 Write a method to compute all permutations of a string.
 * Code based on solution at https://www.youtube.com/watch?v=nYFd7VHKyWQ which covers
 * cases where there is a repeat character in the input string. 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char chars[] = {'A', 'B', 'C'};


void permute (char *str, int depth, int *count, int len) {
	int i=0;
	if (depth > len) {
		printf ("%s\n", str);
		return;
	}
	for (i=0; i<3; i++) {
		if (count[i] == 0)
			continue;
		str[depth] = chars[i];
		count[i]--;
		permute (str, depth+1, count, len);
		count[i]++;
	}
}

/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute2(char *a, int l, int r)
{
   int i;
   if (l == r)
     printf("%s\n", a);
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute2(a, l+1, r);
          swap((a+l), (a+i)); //backtrack
       }
   }
}

/* Driver program to test above functions */
int main()
{
	int count[] = {2,1,1};
	char str[] = "AABC";
	int n = strlen(str);
	permute(str, 0, count, n-1);
	printf ("next:\n");
	permute2 (str, 0, n-1); 
	//printf ("%s\n", str);
	return 0;
}

