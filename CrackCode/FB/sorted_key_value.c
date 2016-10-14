/* Given two sorted input arrays which contain a two element array of [key, value], write a function which multiplies the two arrays together and sums them where the "key" matches. 
 * Example: "v1=[[1,3], [2, 4], [99, 3]]; v2 = [[2,3],[5,9],[99,1]]" results in "15". 
 */

#include <stdio.h>

typedef struct Node {
	int key;
	int value;
} Node;

int 
total_sum (Node a1[], Node a2[], int n, int m) 
{
	int i = 0, j = 0, sum = 0;

	while (i<n && j<m)
	{
		if (a1[i].key == a2[j].key) {
			sum = sum + (a1[i].value * a2[j].value);
			i++;
			j++;
		} else if (a1[i].key < a2[j].key) {
			i++;
		} else {
			j++;
		}
	}
	return sum;
}

int main () 
{
	Node arr1[] = {{1,3}, {2, 4}, {6, 2}, {99, 3}};
	Node arr2[] = {{2,3}, {5, 9}, {99, 1}};

	printf ("Sum = %d.\n", total_sum (arr1, arr2, 4, 3));

	return 0;
}

