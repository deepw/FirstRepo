#include <stdio.h>

int 
rem_dup (char *str, char *result) 
{
	int i = 0, j = 0;

	while (str[i]) {
		if (str[i] == 'b') {
			/* skip it */
		} else if (str[i] == 'a') {
			result[j++] = 'a';
			result[j++] = 'a';
		} else {
			result[j++] = str[i];
		}
		i++;
	}
	return 0;
}

int main () {
	char input[] = "abcab";
	char output[100];
	rem_dup (input, output);
	printf ("input = %s.\n", input);
	printf ("output = %s.\n", output);
	return 0;
}



