#include <stdio.h>

int matcher (char *pattern, char *text) {

	int j=0, k=0;
		while (pattern[j]) {
			if (pattern[j] == '.') {
				j++; k++;
			} else if (pattern[j+1] == '*') {
				while (text[k] == pattern[j])
					k++;
				j = j+2;
			} else {
				if (pattern[j] != text[k]) {
					break;
				} else {
					j++;
					k++;
				}
			}
		}
		if (!pattern[j] && !text[k]) {
			printf ("Match found \n");
		} else {
			printf ("Match not found.\n");
		}
	return 0;
}

int main ()
{
	char t[] = "aaaab";
	char p[] = "a*b";

	matcher (p, t);
	return 0;
}

