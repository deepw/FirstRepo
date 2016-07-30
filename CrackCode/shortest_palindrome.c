/*
 * Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.
 *
 * For example, given "aacecaaa", return "aaacecaaa"; given "abcd", return "dcbabcd".
 * http://www.geeksforgeeks.org/dynamic-programming-set-28-minimum-insertions-to-form-a-palindrome/
 */

#include <stdio.h>


int 
shortest_palindrome (int *s, int start, int end) {
	if (start > end)
		return INT_MAX;
	if (start == end)
		return 0;
	if (start == end-1 && s[start] == s[end])
		return 0;
	if (start == end-1 && s[start] != s[end])
		                return 1;

	if (s[start] == s[end])
		return shortest_palindrome (s, start+1, end-1);
	else
		return (1 + min ( shortest_palindrome (s, start+1, end), shortest_distance (s, start, end-1)));
}


