/* 
 * Write a function that takes a string S and an array of strings A and returns true if S can be reconstructed by any combination of the elements in A
 */

#include <stdio.h>
#include <string.h>

int hash[256];

int 
found_all (int hash[]) {
	int i = 0;
	for (i=0; i<256; i++) {
		if (hash[i])
			return 0;
	}
	return 1;
}

int
reconstruct (char *S, int n, char A[][n], int m) {
	int i = 0, j = 0;

	while (S[i]) {
		hash[S[i]]++;
		i++;
	}

	for (i=0; i<m; i++) {
		j=0;
		while (j < strlen(A[i])) {
			if (hash[A[i][j]]) hash[A[i][j]]--;
			if (found_all(hash)) {
				return 1;
			}
			j++;
		}
		i++;
	}

	return 0;
}

int 
main () {
	char A[][5] = {"abc", "def", "gap", "h", "wxyz"};
	char S[] = "abcpaa";

	printf ("String %s, constructed: %d.\n", S, reconstruct(S, 5, A, 5));
	return 0;
}


