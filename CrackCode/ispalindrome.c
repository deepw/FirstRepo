
#include <stdio.h>
#include <stdlib.h>


int isPalindrome(int x) {
    /* While more than one digits are available */
    int tmp = 0, digits = 0, p = 0, i = 0;
    tmp = x;
    while (tmp>0) {
        tmp=tmp/10;
        digits++;
    }
    while (x/10 > 0) {
        p=1;
	i=0;
        while (i++ < digits-1) {
            p=p*10;
        }
	printf ("p=%d", p);
        if (x/p != x%10) {
            return 0;
        }
        x = x%p;
        x = x/10;
        digits = digits-2;
    }
    return 1;
}

int main () {
    int x = 0;
    printf ("n= ");
    scanf ("%d", &x);
    printf ("Palindome=%d\n", isPalindrome(x));
    return 0;
}


