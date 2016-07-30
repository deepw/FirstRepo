#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void 
compress (char *str) 
{
	int i = 0, j = 0;
	int count = 0;
	char c;
	while (str[i]) 
	{
		count = 0;
		c = str[i];	
		while (c == str[i]) {
			count++;
			i++;
		}
		str[j++] = c;
		if (count > 1) {
			char cn[10];
			int sz = sprintf (cn, "%d", count);
			memcpy (str+j, cn, sz);
			j += sz;
		}
	}	
	str[j] = '\0';
	return;
}

int main ()
{
	char str[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcdd";
	printf ("str=>%s.\n", str);
	compress (str);
	printf ("str=>%s.\n", str);
	return 0;
}
