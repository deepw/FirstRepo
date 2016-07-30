/*
 * 8.2 Write a method that returns all subsets of a set.
 */
#include <stdio.h>
#include <stdlib.h>

int vals[] = {1, 2, 3, 4, 5};
int sub[5];

void print_subsets (int begin, int end, int size, int item) {
    int i =0;
    if (begin > end) 
	    return;
    if (size == 0) {
	    //printf ("\n");
	    return;
    } else if (size == 1) {
	    printf ("%d\t", vals[begin]);
	    //return;
    }
    //printf ("%d\t", item);
    for (i=begin;i<end;i++) {
        printf ("%d\t ", vals[i]);
        print_subsets (begin+1, end, size-1, vals[i]);
        printf ("\n");
    }
    //printf ("\n");
    return;
}


int main (int argc, char *argv[]) {
	int i =0 ;
	int size = 1;
	if (argv[1]) 
		size = atoi(argv[1]);
	printf ("size=%d.\n", size);
	//for (i=0; i<5; i++) {
	    //printf ("{");
	    print_subsets (i, 5, size, vals[i]);
	  //  printf ("\n");
	//}
	printf ("\n");
	return 0;
}
