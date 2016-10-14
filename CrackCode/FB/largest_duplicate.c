#include <stdio.h>

int hash[256];

int max (int a, int b)
{
	if (a>b)
		return a;
	return b;
}

int largest_unique (char *str)
{
	int i = 0, j=0, maxlen = 1;
	if (!str || !str[0]) return 0;

	while (str[i]) 
	{
		if (!hash[str[i]]) {
			hash[str[i]] = 1;
			maxlen = max (maxlen, i-j+1);
			i++;
		} else {
			hash[str[j]] = 0;
			j++;
		}
	}

	return maxlen;
}

int main ()
{
	char str[] = "aabcaafbcd";
	printf ("Maxlen = %d.\n", largest_unique(str));
	return 0;
}



