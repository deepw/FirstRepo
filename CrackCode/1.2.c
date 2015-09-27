/* 
 *  1.2 Write code to reverse a C-Style String. (C-String means that “abcd” is represented as five characters, including the null character.)
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
ReverseString(char *str) {
	char *rptr = NULL;
	char tempc = 0 ;
        rptr = str + strlen(str) - 1;
	while (str < rptr) {
		/* swap the two */
		tempc = *str;
		*str = *rptr;
		*rptr = tempc;
		str++; rptr--;
	}
}

int 
main () {
	char str[200];
	printf("Enter the string.:\n");
	gets(str);
	ReverseString(str);
	printf("Reversed string:%s.\n", str);
	return 0;
}

