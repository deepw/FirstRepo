/*
 * Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 *
 * For example, S = "ADOBECODEBANC", T = "ABC", Minimum window is "BANC".
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int hash[256];

int
isValid (int *hash, char *T)
{
        int i = 0;
        for (i=0; i<strlen(T) ; i++) {
                if (hash[*(T+i)] == 0)
			return 0;
        }
        return 1;
}

/* S = "ADOBECODEBANC", T = "ABC", Minimum window is "BANC". */
int
min_window (char *S, char *T)
{
        int end = 0;
        int start = 0;
        int min = strlen(S)+1;
        int sublen = 0;
        int len = strlen (S);

        memset (hash, 0, sizeof(hash));

        while (end < len) {
		while (!isValid (hash, T)) {
			hash[*(S+end)] += 1;
			end++;
			sublen++;
		}
		printf ("1.sublen=%d, min=%d\n", sublen, min);
		if (sublen < min) {
			min = sublen;
		}

		while (isValid (hash, T) && start<end) {
			hash[*(S+start)] -= 1;
			start++;
			sublen--;
		}
		printf ("2.sublen=%d, min=%d\n", sublen, min);
		if (sublen+1 < min) {
			min = sublen+1;
		}
        }
        return min;
}

int main ()
{
        printf ("Miminum window for %s is of length %d.\n", "ADOBEABCODEBANC", min_window ("ADOBEABCODEBANC", "ABC"));
return 0;
}


