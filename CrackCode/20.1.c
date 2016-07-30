/* 
 * 20.1 Write a function that adds two numbers. You should not use + or any arithmetic op- erators.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
BitWiseAdd(int a, int b) {
	int i=0,abit=0,bbit=0,sbit=0;
	int sum = 0;
	int carry = 0;
	while (a>0 || b>0) {
		abit = (a & 0x1);
		bbit = (b & 0x1);
		sbit = abit | bbit | carry;
		if (abit && bbit && carry) {
			carry = 1;
		} else if ((abit && bbit) || (abit && carry) || (bbit && carry)) {
			sbit = 0;
			carry = 1;
		} else {
			carry = 0;
		}
		sum = sum + sbit *(1 << i);
		i++; a=a>>1; b=b>>1;
	}
	sum = sum + carry *(1<<i);
	return sum;
}

int
main () {
	int a=0,b=0;
	printf ("\na=?:");
	scanf ("%d", &a);
	printf ("\nb=?:");
	scanf ("%d", &b);
	printf ("\nSum = %d.\n", BitWiseAdd (a, b)); 
	return 0;
}

