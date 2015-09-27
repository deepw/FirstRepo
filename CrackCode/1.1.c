/* 
 * 1.1 Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures?
*/

#include <stdio.h>
#include <stdlib.h>

int
isUnique(char *str) {
	int32_t checkint = 0;
	int i = 0, pos = 0;

	while (*str != '\0') {
		pos = *str - 97; 
		if (checkint & (0x1 << pos)) {
			return 0;
		} else {
			checkint |= (0x1 << pos);
		}
		str++;
	}
	return 1;
}

int
main () {
        char str[200];
        printf("Enter string to check:\n");
        gets(str);
        printf ("Unique Characters only: %s.\n", isUnique(str) ? "Yes" : "No");
}
