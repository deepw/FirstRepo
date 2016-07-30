#include <stdio.h>
#include <string.h>

int 
one_edit_away (char *str1, char*str2) 
{
	if (!str1 || !str2) {
		return 0;
	}

	int m = strlen (str1);
	int n = strlen (str2);

	if (m-n > 1 || m-n < -1)
		return 0;

	int i = 0, j = 0, count = 0;
	while (i<m && j<n) {
		if (str1[i] != str2[j]) {
			if (count == 1)
				return 0;

			count = 1;

			if (m > n) {
				i++;
			} else if (m < n) {
				j++;
			} else {
				i++;
				j++;
			}
		} else {
			i++;
			j++;
		}
	}

	if (i<m || j<n) 
		count += 1;

	return (count == 1);
}

int main () 
{
	char str1[] = "carea";
	char str2[] = "cars";

	printf ("%s and %s, one edit away: %d.\n", str1, str2, one_edit_away (str1, str2));
	return 0;
}



