#include <stdio.h>

void print_string(int ip)
{
	int octets = 0;
	while (octets++ < 4) {
		printf ("%d", ((ip & 0xff000000) >> 24));
		ip = ip << 8;
		if (octets < 4)
			printf (".");
	}
	printf ("\n");
}


int main () 
{
	int ip = 0;
	printf ("IP in decimal.?: ");
	scanf ("%x", &ip);
	print_string (ip);
	return 0;
}
