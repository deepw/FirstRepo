/* Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 *
 * For example, "Red rum, sir, is murder" is a palindrome, while "Programcreek is awesome" is not.
 *
 * Note:
 * Have you consider that the string might be empty? This is a good question to ask during an interview.
 *
 * For the purpose of this problem, we define empty string as valid palindrome.
 */

#include <stdio.h>

#if 0
int
remove_duplicates (int *arr, int n) 
{
	int i = 0;
	int j = 0;

	int p = arr[0];
	i=0; j=1;

	while (i < n) {
		repeat = 0;
		p = arr[i];
		while (arr[j] == p) {
			if (!repeated) {
				i++;
				repeated = 1;
			} else {
				arr[i] = arr[j];
			}

			j++;
		}
		j++; i++;
	}
	return 0;
}
#endif

int
remove_duplicates (int *arr, int n, int *final_size) 
{
	int i = 0;
	int j = 0;

	i=0; j=1;

	while (j < n) {
		while (arr[j] == arr[i]) {
			if (j+1<n) {
				j++;
			} else {
				goto finish;
			}
		}
		i++;
		arr[i] = arr[j];
		j++;
	}
finish:
	*final_size=i+1;
	return 0;
}

void print (int *a, int n) 
{
	int i = 0;
	for (i=0; i<n ; i++) {
		printf ("%d\t", a[i]);
	}
	printf ("\n");
}

int main ()
{
	int a1[] = {1,2,2,3,4,5};
	int a2[] = {1,1,1,2,2,2,3,3};
	int a3[] = {1,2,3,4,5,6,6};
	int a4[] = {1,2,3,4,5};
	int sz = 0;
	
	print (a1, 6);
	remove_duplicates (a1, 6, &sz);
	printf ("After removing:\n");
	print (a1, sz);
	printf ("\n");

        print (a2, 8);
        remove_duplicates (a2, 8, &sz);
	printf ("After removing:\n");
        print (a2, sz);
	printf ("\n");

        print (a3, 7);
        remove_duplicates (a3, 7, &sz);
	printf ("After removing:\n");
        print (a3, sz);
	printf ("\n");

        print (a4, 5);
        remove_duplicates (a4, 5, &sz);
	printf ("After removing:\n");
        print (a4, sz);
	printf ("\n");

}

