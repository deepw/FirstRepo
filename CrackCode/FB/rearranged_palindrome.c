#include <stdio.h>

int hash[256];

int 
rearrange_palindrome (char *str) 
{
	int i = 0, count = 0;
	if (!str) return 0;

	while (str[i]) {
		hash[str[i]]++;
		i++;
	}

	for (i=0; i<256; i++) {
		if (hash[i] & 0x1) {
			if (count) {
				return 0;
			}
			count++;
		}
	}
	return 1;
}

int 
main ()
{
	char str[] = "geeksogeeks";
	printf ("%s can be rearranged : %d.\n",  str, rearrange_palindrome (str));
	return 0;
}

