#include <stdio.h>
#include <stdlib.h>

#define NO_OF_CHARS 256
 
/* function to check whether characters of a string can form 
   a palindrome */
int canFormPalindrome(char *str)
{
    // Create a count array and initialize all values as 0
    int count[NO_OF_CHARS] = {0};
 
    // For each character in input strings, increment count in
    // the corresponding count array
    for (int i = 0; str[i];  i++)
        count[str[i]]++;
 
    // Count odd occurring characters
    int odd = 0;
    for (int i = 0; i < NO_OF_CHARS; i++)
        if (count[i] & 1)
            odd++;
     
    // Return true if odd count is 0 or 1, otherwise false
    return (odd <= 1);
}
 
/* Driver program to test to pront printDups*/
int main()
{
  printf ("%s %d.\n", "geeksforgeeks", canFormPalindrome("geeksforgeeks"));
  printf ("%s %d.\n", "geeksogeeks", canFormPalindrome("geeksogeeks"));
  return 0;
}
