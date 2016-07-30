

int edit_d (char *str1, int m, char *str2, int n) 
{
	if (m == 0) return n;
	if (n == 0) return m;

	if (str1[m-1] == str2[n-1]) {
		return edit_d (str1, m-1, str2, n-1);

	else 
		return 1 + min (edit_d (str1, m-1, str2, n), edit_d (str1, m, str2, n-1), edit_d (str1, m-1, str2, n-1));
}

int 
edit_distance (char *str1, int m, char *str2, int n) 
{
	int DP[m+1][n+1];

	for (i=0; i<m; i++) {
		DP[i][0] = i;
	}
	for (j=0; j<n; j++) {
		DP[0][j] = j;
	}

	for (i=1; i<=m; i++) {
		for (j=1; j<n; j++) {
			
			if (str1[i-1] == str2[j-1]) {
				DP[i][j] = DP[i-1][j-1];
			} else {
				DP[i][j] = 1 + min (DP[i-1][j], DP[i][j-1], DP[i-1][j-1]);
			}
		}
	}
	return DP[m][n];
}


