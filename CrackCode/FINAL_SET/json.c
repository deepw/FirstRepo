

#include <stdio.h>

void
newline (int tabs)
{
	printf ("\n");
	for (int i =0; i<tabs; i++) 
		printf ("\t");
}

int
print_pretty (char *json) 
{

	int i = 0;
	int tabs = 0;
	while (json[i]) {
		switch (json[i]) {
			case '{':
			case '[':
				{
					tabs++;
					printf ("%c", json[i]);
					newline (tabs);
					break;
				}
			case ']':
			case '}':
				{
					tabs--;
					newline (tabs);
					printf ("%c", json[i]);
					break;
				}
			case ',':
			case ':':
				{
					printf ("%c", json[i]);
					newline (tabs);
					break;
				}
			default:
					printf ("%c", json[i]);

		}
		i++;
	}
	return 0;
}

int main ()
{
	char str[] = "[\"foo\", {\"bar\":[\"baz\",null,1.0,2]}]";
	print_pretty (str);
	printf ("\n");
	return 0;
}


