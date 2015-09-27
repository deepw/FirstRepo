/*
 * 1.3 Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer. NOTE: One or two additional variables are fine. An extra copy of the array is not.
 * FOLLOW UP
 * Write the test cases for this method. 
*/

#include <stdio.h>
#include <stdlib.h>

int
RemoveDups (char *str) {
	int32_t checkint = 0;
	int i = 0, pos = 0;
	char *ptr = str;

	while (*str != '\0') {
		pos = *str - 97; 
		if (!(checkint & (0x1 << pos))) {
			checkint |= (0x1 << pos);
			*ptr = *str;
			ptr++;
		}
		str++;
	}
	*ptr = '\0';
	return 1;
}

int
main () {
        char str[200];
        printf("Enter string:\n");
        gets(str);
	RemoveDups (str);
        printf ("After removing unique chars: %s.\n", str);
}
