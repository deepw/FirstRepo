#include <stdio.h>
#include <string.h>

int
digit_sequence (char *number, int n) 
{
	int count = 0;

	if (n==0) 
		return 1;

	if (number[n-1] > '0') 
		count = digit_sequence (number, n-1);

	if (n-2 >= 0) {
		if ((number[n-2] > '0' && number[n-2] < '2') || (number[n-2] == '2' && number[n-1] < '7'))
	       		count += digit_sequence (number, n-2);
	}

	return count;
}

int ds (char *number, int n) 
{
	int count[n+1];
	int i = 0;
	count[0] = 1;

	for (i=1; i<=n; i++) {
		count[i] = 0;
		if (number[i-1] > '0')
			count[i] = count[i-1];
		if ((number[i-2] > '0' && number[i-2] < '2') || (number[i-2] == '2' && number[i-1] < '7'))
			count[i] += count[i-2];
	}
	return count[n];
}


int ds2 (char *number, int n) 
{
	int count=0, back=1, back2=1;
	int i = 0;

	for (i=1; i<=n; i++) {
		count = 0;
		if (number[i-1] > '0')
			count = back;
		if ((number[i-2] > '0' && number[i-2] < '2') || (number[i-2] == '2' && number[i-1] < '7'))
			count += back2;
		back2 = back;
		back = count;
		
	}
	return count;
}


int main()
{
    char digits[] = "1234";
    int n = strlen(digits);
    printf ("Count = %d.\n", digit_sequence (digits, n));
    printf ("Count = %d.\n", ds (digits, n));
    printf ("Count = %d.\n", ds2 (digits, n));
    return 0;
}

