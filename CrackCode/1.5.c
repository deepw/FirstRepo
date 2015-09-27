/* 
 * 1.5 Write a method to replace all spaces in a string with ‘%20’.
*/

/* You could keep shifting the same string out */

#include <stdio.h>
#include <stdlib.h>

int
ReplaceSpaces(char *str, char *ptr) {
	while (*str != '\0') {
		if (*str == ' ') {
			*ptr++ = '%';
			*ptr++ = '2';
			*ptr++ = '0';
		} else {
			*ptr++ = *str;
		}
		str++;
	}
	return 1;
}

int
main () {
        char str[200];
	char newstr[300];
        printf("Enter string to check:\n");
        gets(str);
	ReplaceSpaces(str, newstr);
        printf ("Unique Characters only: %s.\n", newstr);
}
