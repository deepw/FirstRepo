#include<stdio.h>


int 
main () 
{
	int i = 0;
	for (i=1; i<=100; i++) {
		if (i%3==0) {
			printf ("fizz ");
		}
		if (i%5==0) {
			printf ("buzz ");
		}
		if (i%3 && i%5) {
			printf ("%d ", i);
		}
	}
	return 0;
}


