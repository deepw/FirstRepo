/* find largest element in non transitive sequence of elements.  
 */


#include <stdio.h>


int
find_largest (int arr[], int n) 
{
	int i= 0;

	int best = 0;
	for (i=1; i<n; i++) {
		if (mycmp (arr[best], arr[i])) {
			best = i;
		}
	}

	for (i=0; i<n; i++) {
		if (!mycmp(arr[best], arr[i])) {
			return -1;
		}
	}
	return best;
}
