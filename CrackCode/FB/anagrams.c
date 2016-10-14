#include <stdio.h>

typedef struct item {
	char str[n];
	int index;
} Item;

Item* mycompare (Item *a, Item *b) 
{
	return (strcmp(a->str, b->str));
}

int
group_anagrams (char list[][n], int m, int n, char result[][n]) 
{
	Item dup[m];
	int i = 0;

	for (i=0; i<m; i++) {
		dup[i].index = i;
		strncpy (dup[i].str, list[i], n);
	}

	/* Sort each string individually */
	for (i=0; i<m; i++) {
		sort (dup[i]);
	}

	/* Sort the items in the dup array */
	sort (dup, n, mycompare);

	for (i=0; i<m; i++) {
		strncpy (result[i], list[dup[i].index], n);
	}
	return 0;
}

