#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max (int a, int b) {
	if (a>b)
		return a;
	else
		return b;
}

int add (char *number1, char *number2, char **result)
{
	int i, j, k, carry, sum;
	if (!number1 && !number2) {
		*result = NULL;
	}
	if (!number1) {
		*result = strdup(number2);
		return 0;
	}
	if (!number2) {
		*result = strdup(number1);
		return 0;
	}
	int len1 = strlen(number1);
	int len2 = strlen(number2);

	int result_len = max(len1, len2) + 2;
	char *result_str =  malloc(result_len);

	i = len1-1;
	j = len2-1;
	k = result_len-2;
	result_str[result_len-1] = '\0';

	carry=0;
	while (i>=0 && j>=0) {
		sum = number1[i] - '0' + number2[j] - '0' + carry;
		result_str[k] = sum%10 + '0' ;
		carry = sum/10;
		i--;j--;k--;
	}

	while (i>=0) {
		sum = number1[i] - '0'  + carry;
		result_str[k] = sum%10 + '0' ;
		carry = sum/10;
		i--; k--;
	} 

	while (j>=0) {
		sum = number2[j] - '0' + carry;
		result_str[k] = sum%10 + '0' ;
		carry = sum/10;
		j--; k--;
	} 

	if (carry) {
		result_str[k] = '1';
	} else {
		result_str[k] = '0';
	}

	*result = result_str;

	return 0;
}

int main () {
	char n1[] = "99999999999";
	char n2[] = "9";

	char *n3 = NULL;
	add (NULL, n2, &n3);
	printf ("%s + %s = %s.\n", n1, n2, n3);
	return 0;
}
