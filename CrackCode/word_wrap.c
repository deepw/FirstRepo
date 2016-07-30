



int
wordwrap (char *str, int n) {
	DP[n] = 0;

	for (i=n; i>=0; i++) {
		for (j=i+1; j<n+1; j++) {
			DP[i] = min (DP[i], badness(i,j));
		}
	}
}

	
