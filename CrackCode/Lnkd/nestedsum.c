
#include <stdio.h>
#include <stdlib.h>

int sum(char *input) 
{
	int i =0;
	int total = 0;
	int level = 0;
	while (input[i] != '\0') {
		//printf ("%c\n", input[i]);
		if (input[i] == '{') {
			level++;
		} else if (input[i] != ',') {
			char num[10];
			int k=0;
			while (input[i] != ',' && input[i] != '}') {
				num[k]=input[i];
				k++; i++;
			}
				num[k]='\0';
				int number = atoi(num);
				//printf ("num=%d level=%d.\n", number, level);
				total = total+(number*level);
				if (input[i] == '}')
					level--;
		}
		i++;
	}
	return total;
}

int 
nested_sum (char *input)
{
	int i = 0;
	int sum = 0;
	int depth = 0;

	while (input[i]) {
		if (input[i] == '{') {
			depth++;
		} else if (input[i] == '}') {
			depth--;
		} else if (input[i] != ',') {
			sum = sum + (depth * (input[i] - '0'));
		}
		i++;
	}
	return sum;
}



int main ()
{
	char str[] = "{{1,1},2,{1,1}}";
	char str2[] = "{1,{4,{6}}}";
	printf ("sum for %s is %d.\n", str2, sum(str2));
	printf ("sum for %s is %d.\n", str2, nested_sum (str2));
	printf ("sum for %s is %d.\n", str, sum(str));
	printf ("sum for %s is %d.\n", str, nested_sum (str));
	return 0;
}
