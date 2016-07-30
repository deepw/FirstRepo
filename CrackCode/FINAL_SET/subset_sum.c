

int 
subset_sum (int set[], int n, int sum) 
{
	if (sum == 0) 
		return 1;
	if (n == 0 && sum != 0) 
		return 0;

	if (set[n-1] > sum) {
		return subset_sum (set, n-1, sum);

	return (subset_sum (set, n-1, sum), subset_sum (set, n-1, sum-set[n-1]));
}

int 
subset_sum (int set[], int n, int sum) 
{
	DP [sum+1][n+1];


	for (i=0; i<=sum; i++) {
		for (j=0; j<=n; j++) {
			if (i==0) {
				DP[i][j] = 1;
			} else if (j==0 && i != 0) {
				DP[i][j] == 0;
			} else if (set[j-1] > i) {
				DP[i][j] = DP[i][j-1];
			} else {
				DP[i][j] = DP[i][j-1] || DP[i-set[j-1]][j-1];
			}
		}
	}

	return [sum][n];
}



