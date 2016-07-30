#include <stdio.h>

int hash[256];

int 
remove_duplicates (char *str)
{
	int i = 0, j = 0;
	if (!str) return -1;
	while (str[i]) {
		if (!hash[str[i]]) {
			hash[str[i]] = 1;
			str[j++] = str[i];
		}
		i++;
	}
	str[j] = '\0';
	return 0;
}

int main () 
{
	char str[] = "abbbcdserfesb";
	printf ("%s.\n", str);
	remove_duplicates (str);
	printf ("%s. \n", str);
	return 0;
}
