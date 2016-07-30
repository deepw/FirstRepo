#include <stdio.h>
#include <string.h>

void 
reverseUtil (char *words, int i, int j) {
	char c;
	while (i<j) {
		c = words[i];
		words[i] = words[j];
		words[j] = c;
		i++; j--;
	}
}

int
reverse_words (char *str) {
	int i=0, j=0;
	if (!str) return -1;

	while (str[i]) {
		j=i;
		while (str[j] && str[j] != ' ') {
			j++;
		}
		reverseUtil (str, i, j-1);
		while (str[j] == ' ')
			j++;
		i=j;
	}
	reverseUtil (str, 0, strlen(str)-1);
	return 0;
}

int main ()
{
	char str[] = "  these are some words";
	//char str[] = "t    two";
	printf ("String: %s\n", str);
	reverse_words (str);
	printf ("Reversed: %s\n", str);
	return 0;
}
