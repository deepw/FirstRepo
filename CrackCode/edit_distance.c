#include <stdio.h>
#include <string.h>

int min (int a, int b, int c)
{
	if (a<b) {
		if (a<c) {
			return a;
		}
		return c;
	} else {
		if (b<c) {
			return b;
		} 
		return c;
	}
}

int edit_distance (char * str1, char *str2, int m, int n)
{
	if (n == 0)
		return m;
	if (m == 0) 
		return n;

	if (str1[m-1] == str2[n-1]) {
		return edit_distance (str1, str2, m-1, n-1);
	} else {
		return 1 + min (edit_distance (str1, str2, m-1, n), edit_distance (str1, str2, m, n-1), edit_distance (str1, str2, m-1, n-1));
	}
}

int edit_distance2 (char *str1, char *str2, int m, int n)
{
	int i=0, j=0;
	int result[m+1][n+1];

	for (i=0; i<m; i++) result[i][0] = i;
	for (j=0; j<n; j++) result[0][j] = j;

	for (i=0; i<=m; i++) {
		for (j=0; j<=n; j++) {
			if (j==0)
				result[i][j] = i;
			else if (i==0)
				result[i][j] = j;
			else if (str1[i-1] == str2[j-1])
				result[i][j] = result[i-1][j-1];
			else
				result[i][j] = 1+ min(result[i-1][j], result[i][j-1], result[i-1][j-1]);
		}
	}
	for (i=0;i<=m;i++) {
		for (j=0;j<=n;j++) {
			printf ("%d ", result[i][j]);
		}
		printf ("\n");
	}
	return result[m][n];
}

int main () {
	char str1[] = "accd";
	char str2[] = "acc";

	printf ("Edit distance of %s and %s = %d.\n", str1, str2, edit_distance (str1, str2, strlen(str1), strlen(str2)));
	printf ("Edit distance 2 of %s and %s = %d.\n", str1, str2, edit_distance2 (str1, str2, strlen(str1), strlen(str2)));
	return 0;
}

