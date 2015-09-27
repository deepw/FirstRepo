/* 
 * 1.1 Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures?
*/

/* Another interesing way to check this is to see if s2 is a substring of concat(s1, s1). */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
isRotated (char *str, char *str2) {
	int i = 0, found = 0;
	char *ptr = str;
	char *ptr2 = str2;

	while (*ptr != '\0') {
	       while (!found && *ptr == *ptr2) {
			ptr++; ptr2++;
			if (*ptr == '\0') {
				found = 1;
				goto foundit;
			}
	       } 
		ptr2 = str2;
		ptr++;	
	}

foundit:
	if (found && strstr(str, ptr2) && (strlen(str)== strlen(str2)))
		return 1;

	return 0;
}

int
main () {
        char str[200];
        printf("Enter string to check:\n");
        gets(str);
        char str2[200];
        printf("Enter string to check:\n");
        gets(str2);
        printf ("Rotated String?: %s.\n", isRotated(str, str2) ? "Yes" : "No");
}
