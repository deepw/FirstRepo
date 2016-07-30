#include <stdio.h>
#include <string.h>

void
print (char *str, int i, int j) {
	while (i <= j) {
		printf ("%c", str[i]);
		i++;
	}
	printf ("\n");
}

int all_palindromes (char *str) {
	int r=0, i=0;
	if (!str) return -1;

	while (str[i]) {
		/* find all odd length palindomes with center at i and radius r */
		r=1;
		while (i-r >= 0 && i+r < strlen(str) && str[i-r] == str[i+r]) {
			print (str, i-r, i+r);
			r++;
		}

		/* find all even length palindromes with i and i+1 as center */
		r=0;
		while (i-r >= 0 && i+r+1 < strlen(str) && str[i-r] == str[i+r+1]) {
			print (str, i-r, i+r+1);
			r++;
		}
		i++;
	}
	return 0;
}

int main () {
	char str[] = "aababbab";
	all_palindromes (str);
	return 0;
}
