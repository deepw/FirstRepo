#include <stdio.h>


int 
prefix (char *expr, int *result) 
{
	if (!expr) return -1;
	int len = strlen (expr) - 1;
	int n1=0, n2=0;

	while (len >= 0) 
	{
		if (isOperator(expr[len])) {
			n1 = pop (&s);
			n2 = pop (&s);
			r = Evaluate (expr[len], n1, n2);
			push (&s, r);
		} else {
			push (&s, expr[len] - '0');
		}
		len--;
	}
	*result = pop (&s);
	return 0;
}

