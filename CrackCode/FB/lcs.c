#include <stdio.h>

int lcs (char *str1, int m, char *str2, int n) 
{
	if (!m || !n) return 0;

	if (str1[m-1] == str2[n-1]) {
		return (1+lcs (str1, m-1, str2, n-1));
	} else {
		return (max (lcs(str1, m-1, str2, n), lcs (str1, m, str2, n-1)));
	}
}

int lcs_memoized (char *str1, int m, char *str2, int n)
{
	if (!m || !n) return 0;
	int DP[m+1][n+1];
	int i=0, j=0;

	for (i=0; i<=m; i++) {
		for (j=0; j<=n; j++) {
			if (i==0 || j==0) {
				DP[i][j] = 0;
			} else if (str1[i-1] == str2[j-1]) {
				DP[i][j] = 1+DP[i-1][j-1];
			} else {
				DP[i][j] = max (DP[i-1][j], DP[i][j-1]);
			}
		}
	}

	return DP[m][n];
}




