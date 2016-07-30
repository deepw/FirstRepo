#include <stdio.h>

void
count_and_say (int n) {
	int i = 0, num = 0, j = 0, k = 0, count = 0;
	char result[n][1000];

	result[0][0] = '1';
	result[0][1] = '\0';
	for (i=1; i<n; i++) {

		count = 0; num = 0; j = 0, k=0;
		while (result[i-1][j] != '\0') {
			num = result[i-1][j];
			j++;
			count = 1;
			while (result[i-1][j] != '\0' && num == (result[i-1][j])) {
				count++;
				j++;
			}
			if (result[i-1][j] == '\0') {
				break;
			}
			result[i][k++] = count + '0';
			result[i][k++] = num;
			//j++;
		}
		result[i][k++] = count + '0';
		result[i][k++] = num;
		result[i][k] = '\0';
	}
	for (i=0; i<n; i++) {
		printf ("%d th number is %s k=%d.\n", i, result[i], k);
	}
}

int main () {
	count_and_say (20);
	return 0;
}


		

