/*
 * 1.4 Write a method to decide if two strings are anagrams or not. 
 * 
*/

/* The other way to do ths is to sort both the string and then compare them.
 * About the same complexity. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
CheckAnagram (char *str1, char *str2) {
	int32_t check[26], check0[26];
	int i = 0, pos = 0;

	memset(check, 0, sizeof(check));
	memset(check0, 0, sizeof(check));
	while (*str1 != '\0') {
		pos = *str1 - 97; 
		check[pos]++;
		str1++;
	}
	while (*str2 != '\0') {
		pos = *str2 - 97; 
		if (--check[pos] < 0)
			return 0;
		str2++;
	}
	return !(memcmp(check, check0, sizeof(check)));
}

int
main () {
        char str1[200];
	char str2[200];
        printf("Enter string 1:\n");
        gets(str1);
        printf("Enter string 2:\n");
        gets(str2);
        printf ("Anagrams?: %s.\n", CheckAnagram (str1, str2) ? "Yes" : "No");
	return 0;
}
