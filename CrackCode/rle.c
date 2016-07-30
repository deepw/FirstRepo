#include <stdio.h>
#include <string.h>
/*
 *
 * a a b b b c c c
 * r r r
 * w w w
 * a 2
 *
 *
 */
int
rle (char *str)
{
	int count = 0, w=0;
	if (str == NULL)
		return -1;

	char *write = str; 
	char *read = str;

	printf ("str=%s\n", str);
	while (*read != '\0') 
	{
		*write = *read;
		read++; count=1;
		while (*read == *write) {
			count++;
			read = read+1;
		}
		write=write+1;
		if (count>1) {
			char str[10];
			w = sprintf (str, "%d", count);
			memcpy (write, str, w);
			write += w;
		}
	}
	*write = '\0';
	return 0;
}

int main () 
{
	char str[] = "aabbbccc";
	char str2[] = "aaaaa";
	char str3[] = "abcd";
	char str4[] = "aabbbbbbbbbbbbccc";

	rle (str);
	printf ("%s\n", str);

	rle (str2);
	printf ("%s\n", str2);

	rle (str3);
	printf ("%s\n", str3);

	rle (str4);
	printf ("%s\n", str4);


	return 0;
}

