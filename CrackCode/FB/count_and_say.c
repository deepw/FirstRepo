#include <stdio.h>


void 
count_and_say (int number) 
{
	char result[number+1][10000];

	int i=0, j=0, k=0, tmp=0, count=0;
	result[0][0] = '1';
	result[0][1] = '\0';
	printf ("%d -> %s\n", i+1, result[i]);
	for (i=1; i<number; i++) {
		j=0; k=0;
		while (result[i-1][j]) {
			tmp = result[i-1][j];
			count = 0;
			while (result[i-1][j] && result[i-1][j] == tmp)  {
				j++;
				count++;
			}
			result[i][k++] = count + '0';
			result[i][k++] = tmp;
		}
		result[i][k] = '\0';
		printf ("%d -> %s\n", i+1, result[i]);
	}
	return ;
}

int main () {
	count_and_say (40);
	return 0;
}



