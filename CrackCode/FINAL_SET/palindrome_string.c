/*
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 *
 * For example, "Red rum, sir, is murder" is a palindrome, while "Programcreek is awesome" is not.
 *
 * Note:
 * Have you consider that the string might be empty? This is a good question to ask during an interview.
 *
 * For the purpose of this problem, we define empty string as valid palindrome.
 */

#include <stdio.h>
#include <string.h>

#define DIFF 'a' - 'A'
int
isamatch (char a, char b) {
	if (a==b || a==b+DIFF || b == DIFF+a)
		return 1;
	else 
		return 0;
}


int skipit (char a) {
	if ((a >= 'A' && a <= 'Z') || (a>= 'a' && a <= 'z'))
	       return 0;
	return 1;
}	

int palindrome (char *str) 
{	
	if (!str)	return 1;
	int i = 0;
	int j = strlen(str) -1;

	while (i<j) {
		while (i<j && skipit (str[i])) i++;
		while (i<j && skipit (str[j])) j--;

		if (i<j) {
			if (!isamatch (str[i], str[j])) {
				return 0;
			}
		}
		i++;
		j--;
	}
	return 1;
}


int main () 
{
	char str[] = "abcba";
	char str1[] = "abcBa";
	char str2[] = "abba";
	char str3[] = "abcda";
	char str4[] = "??abc??b?a?";
	char str5[] = "Red rum, sir, is murder";
	char str6[] = "Red rum, sir, is urder";
	char str7[] = "12@#.Race@#car";

	printf ("string %s is palindrome: %d\n", str, palindrome(str));
	printf ("string %s is palindrome: %d\n", str1, palindrome(str1));
	printf ("string %s is palindrome: %d\n", str2, palindrome(str2));
	printf ("string %s is palindrome: %d\n", str3, palindrome(str3));
	printf ("string %s is palindrome: %d\n", str4, palindrome(str4));
	printf ("string %s is palindrome: %d\n", str5, palindrome(str5));
	printf ("string %s is palindrome: %d\n", str6, palindrome(str6));
	printf ("string %s is palindrome: %d\n", str7, palindrome(str7));

	return 0;
}
