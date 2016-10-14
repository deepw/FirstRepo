#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char phonepad[][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void
print_comb (int number[], int n, int pos, char *result) 
{
	int i=0;
	if (pos == n) {
		printf ("%s\n", result);
		return;
	}

	if (strlen(phonepad[number[pos]]) == 0) {
			result[pos] = ' ';
			print_comb (number, n, pos+1, result);
	}

	for (i=0; i < strlen(phonepad[number[pos]]); i++) {
		result[pos] = phonepad[number[pos]][i];
		print_comb (number, n, pos+1, result);
	}

	return;
}

int main ()
{
	int num[] = {2, 0, 4};
	int size = sizeof(num)/sizeof(num[0]);
	//char *result = malloc(size+1);
	char result[size+1];
	result[size] = '\0';
	print_comb (num, size, 0, result);

	return 0;
}

