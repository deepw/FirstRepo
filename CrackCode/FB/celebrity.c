

int 
celebrity (int n, int matrix[][n]) 
{
	int a=0;
	int b=n-1;

	while (a != b) {
		if (matrix[a][b]) {
			a++;
		} else {
			b--;
		}
	}

	for (i=0; i<n; i++) {
		if (i != a && (matrix[a][i] || !matrix[i][a])) {
			return -1;
		}
	}

	return a;
}
