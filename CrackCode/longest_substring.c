/*
 * Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
 * For "bbbbb" the longest substring is "b", with the length of 1.
 * Given a string, find the longest substring that contains only two unique characters. For example, given "abcbbbbcccbdddadacb", the longest substring that contains 2 unique character is "bcbbbbcccb".
 */

#include <stdio.h>
#include <string.h>

char str[] = "abcbefbcbdefbu";

/* 0 implies the character is not in the hash. non zero integer value implies the position where the character exists 
 * Since repeating characters can not exist in the substring, there is no conflicts in the hash table 
 */
int hash[256];
int pos[256];

int
longest_substring (char *s) 
{
	int end = 0;
	int max = 1;
	int sublen = 0;
	int len = strlen (s);

	while (end < len) {
		if (hash[*(s+end)] == 0) {
			hash[*(s+end)] = end+1;
			sublen++;
                        end++;
		} else {
			end = hash[*(s+end)];
			/* reset hash */
			memset (hash, 0, sizeof(hash));
		        if (sublen > max) {
				printf ("string len=%d, end=%d.\n", sublen, end);
			      max = sublen;
		         }
		         sublen = 0;
                }
	}
        if (sublen > max) {
	printf ("string len=%d, end=%d.\n", sublen, end);
                max = sublen;
        }
	return max;
}

/* Instead of going back to the character to compare, just use a start pointer 
 */
int
longest_substring_opt (char *s) 
{
	int end = 0;
	int start = 0;
	int max = 1;
	int sublen = 0;
	int len = strlen (s);

	while (end < len) {
		if (hash[*(s+end)] == 0) {
			hash[*(s+end)] = end+1;
		} else {
			/* reset hash */
		        if (end - start > max) {
				printf ("string len=%d, end=%d.\n", end-start, end);
			      max = end - start;
		         }
		         start = hash[*(s+end)];
                }
                end++;
	}
        if (end-start > max) {
	printf ("string len=%d, end=%d.\n", end-start, end);
                max = end-start;
        }
	return max;
}

int 
UniqueChars (int *hash, int n) 
{
	int i = 0, count = 0;
	for (i=0; i<n ; i++) {
		if (hash[i] > 0)
			count++;
	}
	return count;
}

/* abcadcacacaca" and 3, it returns "cadcacacaca" */
int
longest_substring_k_uniq_chars (char *s, int k) 
{
	int end = 0;
	int start = 0;
	int max = 1;
	int sublen = 0;
	int len = strlen (s);

	memset (hash, 0, sizeof(hash));

	while (end < len) {
		while (UniqueChars (hash, 256) <= k) {
			hash[*(s+end)] += 1;
			sublen++;
			end++;
		}
		if (sublen-1 > max) {
			max = sublen-1;
		}
		while (UniqueChars (hash, 256) > k) {
			hash[*(s+start)] -= 1;
			start++;sublen--;
		}
	}
	return max;
}

int main ()
{
	printf ("Longest substring for %s is of length %d.\n", str, longest_substring (str));
	printf ("Longest substring opt for %s is of length %d.\n", str, longest_substring_opt (str));
	printf ("Longest substring with %d uniq chars in %s is of length %d.\n", 3, "abcadcacacaca", longest_substring_k_uniq_chars ("abcadcacacaca", 3));
	printf ("Longest substring with %d uniq chars in %s is of length %d.\n", 3, "aabacbebebe", longest_substring_k_uniq_chars ("aabacbebebe", 3));
	return 0;
}
