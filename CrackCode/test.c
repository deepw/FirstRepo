#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
int main () {
	char new[20];
	char *token, *save;
	char str[] = "abcd.";
	char * tmp = (char*)malloc(1);
	tmp[0]='\0';
	snprintf (new, 20, "%s.%s", tmp, "printed");
	//printf ("%s", new);
	token = strtok_r(str, ".", &save);
	printf ("t=%s\n", token);
	token = strtok_r(NULL, ".", &save);
	printf ("t=%s\n", token);
	printf ("sizeof(float)=%lu sizeof(ptr)=%lu.\n", sizeof(float), sizeof(save));
	return 0;
}
*/

#define MAX (0x1 << (8*sizeof(int))) - 1
int main ()
{
	char x[10];
	int a;
	printf ("int=>%lu address->%lu.\n", sizeof(a), sizeof(&a));
	return 0;
}
