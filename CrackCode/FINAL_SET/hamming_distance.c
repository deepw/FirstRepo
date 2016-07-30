
int
hamming_distance (char *n1, char *n2) 
{
	int len = strlen (n1) -1 ;
	int count = 0;

	while (len >= 0)
	{
		if ((n1[len]-'0') ^ (n2[len]-'0'))
			count++;
	
		len--;
	}
	return count;
}

int
hamming_distance (int n1, int n2) 
{
	int len = sizeof(int);
	int count = 0;
	int shift = 0;

	while (len > 0)
	{
		if ((n1 & 0x1) ^ (n2 & 0x1))
			count++;
	
		len--;
		n1 >> 1;
		n2 >> 1;

	}
	return count;
}

int
sum_of_all_pairs (int n, int input[]) 
{
	int count = 0;
	int len = sizeof(int);
	int countOnes[len];
	int i = 0, j = 0;
	for (i=0; i<len; i++) {
		for (j=0; j<n; j++) {
			CountOnes[i] += ((input[j] >> i) & 0x1);
		}
	}

	for (i=0; i<len; i++) {
		count += CountOnes[i] * (len - CountOnes[i]);
	}

	return count;
}



			

