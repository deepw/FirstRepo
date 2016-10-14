/* Given a set of strings, return the smallest subset that contains prefixes for every string.
 *
 * If the list is ['foo', 'foog', 'food', 'asdf'] return ['foo', 'asdf'] 
 */


typedef struct trienode {
	struct trienode *children[ALPHABET_SIZE];
	char c;
	int isLeaf;
} trienode;


trienode *
newnode (char c) {
	int i=0;
	trienode * node = malloc (sizeof (trienode));
	for (i=0; i<ALPHABET_SIZE; i++) 
		node->children[i] = NULL;
	node->c = c;
	node->isLeaf = 0;
	return node;
}


void
Insert (trienode *root, char *key) 
{
	trienode *walk = root;

	int len = strlen (key);
	int level = 0;

	for (level=0; level < len; level++) {
		index = key[level] - 'a';
		if (!walk->children[index])
			walk->children[index] = getnode(key[level]);
		walk = walk->children[index];
	}

	walk->isLeaf = 1;
}

find_subset (trienode *root, int n, int *index, int level, char result[][n])
{
	result[*index][level] = root->c;
	if (root->isLeaf) {
		result[*index][level+1] = '\0';
		*index++;
		return;
	}

	for (i=0; i<ALPHABET_SIZE; i++) {
		if (root->children[i]) {
			find_subset (root->children[i], n, index, level+1, result);
		}
	}

	return;
}

int 
find_all (int m, int n, char input[][n], char result[][n])
{
	int i = 0;
	trienode *root = newnode (0);
	for (i=0; i<m; i++) {
		Insert (root, input[i]);

	int index = 0;
	for (i=0; i<ALPHABET_SIZE; i++) {
		if (root->children[i]) {
			find_subset (root->children[i], n, &index, 0, result);
		}
	}
	return;
}





