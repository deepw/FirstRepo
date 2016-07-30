/*
 * 5.2 Given a (decimal - e.g. 3.72) number that is passed in as a string, 
 * print the binary rep-resentation. 
 * If the number can not be represented accurately in binary, print “ERROR”
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int 
ConInt(char *str) {
	int len = strlen (str);
	int num = 0; int i = 0;
	len -= 1;
	while (len >= 0) {
		num += ((str[len]-48) * pow(10, i));
		i++;
		len--;
	} 
	return num;
}


void PrintWhole (int whole) {
	char str[20];
	int len = 0;
	while (whole > 0) {
		str[len++] = ((whole%2) + 48);
		whole = whole/2;
	}
	while (len>=0) 
		printf("%c", str[--len]);
	return;
}


void 
PrintFraction (char *fraction) {
	int len = 0;
	len = strlen (fraction);
	int fractionint = ConInt(fraction);
	float num = 0;
	float factor = pow (10,len);
	num = fractionint/factor;
	//printf ("num=%f\n", num);
	int count = 0;
	while (num > 0) {
		num = num * 2;
		if (num >= 1) {
			printf("1");
			num = num-1.0;
		} else {
			printf("0");
		}
		if (count++ > 32) {
			printf ("\nERROR\n");
			return;
		}
	}
}
		
void
Convert (char *str) {
	char whole[10];
	char fraction[10];
	char *w = whole;
	char *f = fraction;
	memset (whole, 0, sizeof(whole));
	memset (fraction, 0, sizeof(fraction));
	while (*str != '.' && *str != '\0') {
		*w = *str;
		w++; str++;
	}
	while (*str != '\0') {
		if (*str=='.') {
			str++;
			continue;
		}
		*f = *str;
		f++; str++;
	}
	printf("%s.%s\n", whole, fraction);
	PrintWhole(ConInt(whole));
	printf(".");
	PrintFraction(fraction);
	return;
}


int 
main () 
{
	char number[10];
	printf ("Provide the decimal number to be converted to binary.:\n");
	gets(number);
	printf ("Binary representaion: ");
	Convert (number);
	printf ("\n");
	return 0;
}


