#include <stdio.h>
#include <stdlib.h>


/* FOLLOWING FUNCTIONS ARE ONLY FOR SORTING 
    PURPOSE */
void exchange(int *a, int *b)
{
    int temp;
    temp = *a;
    *a   = *b;
    *b   = temp;
}
 
int partition(int A[], int si, int ei)
{
    int x = A[ei];
    int i = (si - 1);
    int j;
 
    for (j = si; j <= ei - 1; j++)
    {
        if(A[j] <= x)
        {
            i++;
            exchange(&A[i], &A[j]);
        }
    }
    exchange (&A[i + 1], &A[ei]);
    return (i + 1);
}
 
/* Implementation of Quick Sort
A[] --> Array to be sorted
si  --> Starting index
ei  --> Ending index
*/
void quickSort(int A[], int si, int ei)
{
    int pi;    /* Partitioning index */
    if(si < ei)
    {
        pi = partition(A, si, ei);
        quickSort(A, si, pi - 1);
        quickSort(A, pi + 1, ei);
    }
}

int sum3(int *S, int n, int t) {
    int i=0, start = 0, end = 0;
    quickSort (S, 0, n);
    for (i=0;i<n-2;i++) {
        start = i;
        end = n;
        
        while (start < end) {
            if (*(S+i) + *(S+start) + *(S+end) == t) {
                printf ("%d %d %d\n", *(S+i), *(S+start), *(S+end));
            }
            if (*(S+i) + *(S+start) + *(S+end) < t) {
                start++;
            } else {
                end--;
            }
        }
    }
    return 0;
}

int
main () {

    int S[] = {-1, 0, 1, 2, -1, -4};
    sum3 (S, sizeof(S)/sizeof(S[0])-1, 0);

    return 0;
}

