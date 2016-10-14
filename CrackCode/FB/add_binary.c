/* 
 * Take binary expansions as strings, and return the string containing their sum: add("10010", "101") = "10111".  
 */

#include <stdio.h>
#include <string.h>

int max (int a, int b) {
	if (a>b)
		return a;
	return b;
}
int
add_binary (char *n1, char *n2, char *result) 
{
	if (!n1 && !n2) return -1;
	if (!n1) strcpy (result, n2);
	if (!n2) strcpy (result, n1);

	int len1 = strlen (n1) - 1;
	int len2 = strlen (n2) - 1;
	int s = 0, carry = 0, k = max(len1, len2) + 2, b1, b2;

	result[k--] = '\0';
	while (len1 >= 0 || len2 >= 0) 
	{
		if (len1 >=0)
			b1 = n1[len1] - '0';
		else 
			b1 = 0;

		if (len2 >= 0)
			b2 = n2[len2] - '0';
		else 
			b2 = 0;

		s = b1 + b2 + carry;
		result[k--] = (s % 2) + '0';;
		carry = s/2;

		len1--;
		len2--;
	}
	if (carry) 
		result[k] = '1';
	else
		result[k] = '0';
	return 0;
}

int main ()
{
	char n1[] = "10010";
	char n2[] = "101";

	char sum[7];

	add_binary (n1, n2, sum);
	printf ("%s.\n", sum);

	return 0;
}
	


