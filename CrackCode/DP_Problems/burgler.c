#include <stdio.h>

int max_robbery (int homes[], int N)
{
	int DP[N+1];

	DP[0] = 0;
	DP[1] = homes[0];
	
	for (i=2; i<=N; i++) {
		DP[i] = max (DP[i-1], homes[i-1]+DP[i-2]);
	}

	return DP[N];
}
