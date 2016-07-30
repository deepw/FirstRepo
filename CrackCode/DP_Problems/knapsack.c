/* Knapsack */

#include <stdio.h>
#include <stdlib.h>

#define N 5
#define S 6

int Values[N] = {5,5,4,3,2};
int Sizes [N] = {4,1,2,3,1};
int Keep [N+1][S+1];
int Max[N+1][S+1];

int max (int a, int b) {
	if (a>b) 
		return a;
	return b;
}

/*
int knapsack (int *V, int *Sizes, int size, int i, int n) {
        int withi=0, withouti=0;
	printf ("Called size=%d, i=%d\n", size, i);
	if (i > n)
		return 0;

	if (Max[i][size] != -1)
		return Max[i][size];

	if (*(Sizes+i) > size) 
		return knapsack (V, Sizes, size, i+1, n);

        withi = knapsack (V, Sizes, size - (*(Sizes+i)), i+1, n) + *(V+i);
        withouti = knapsack (V, Sizes, size, i+1, n);
        if (withi > withouti) {
             Keep[i] = 1;
        }
	Max[i][size] = max (withi, withouti);
	return Max[i][size];
}
*/

int knapsack2 (int *V, int *Si, int size, int start, int n) {

	if (start > n || size == 0) {
		return 0;
	}

	if (*(Si+start) > size) {
		return knapsack2 (V, Si, size, start+1, n);
	}

	return max (knapsack2 (V, Si, size, start+1, n), knapsack2 (V, Si, size-(*(Si+start)), start+1, n) + *(V+start));

}

int knapsack2_memoized(int *V, int *Si, int size, int start, int n) {
        int includei=0, nincludei=0;

        if (start > n || size == 0) {
                return 0;
        }
        if (Max[start][size] != -1) {
                return Max[start][size];
        }

        if (*(Si+start) > size) {
                return knapsack2_memoized (V, Si, size, start+1, n);
        }

	/* WRONG 
        Max[start+1][size] = knapsack2_memoized (V, Si, size, start+1, n);
        Max[start+1][size-*(Si+start)] = knapsack2_memoized (V, Si, size-(*(Si+start)), start+1, n) + *(V+start);
        */
        includei = knapsack2_memoized (V, Si, size-(*(Si+start)), start+1, n) + *(V+start);
	nincludei = knapsack2_memoized (V, Si, size, start+1, n);

	Max[start][size] = max (includei, nincludei);
	
	if (includei > nincludei) {
		Keep[start][size] = 1;
	} else {
		Keep[start][size] = 0;
	}
        return Max[start][size];
}

int knapsack_wihtout_recursion() { 
	int s = 0, n = 0;

	for (s=0; s<=S; s++) {
		for (n=N; n>=0; n--) {
			if (Sizes[n] > s)
				Max[n][s] = 0;
			else
				Max[n][s] = max (Max[n+1][s], Max[n+1][s-Sizes[n]]+Values[n]);
		}
	}
	return Max[0][S];
}

int main () {
        int i = 0, j = 0, s = 0;
	for (i=0; i<=N; i++) {
		for (j=0; j<=S; j++) {
	            Max[i][j] = -1;
	            Keep[i][j] = 0;
		}
	}
	//printf ("Max Value = %d.\n", knapsack(Values, Sizes, S, 0, N));
	//printf ("Max Value = %d.\n", Max[0][S]);
	printf ("\nMax Value 2 = %d.\n", knapsack2 (Values, Sizes, S, 0, N-1));
	printf ("\nMax Value 2 mem = %d.\n", knapsack2_memoized (Values, Sizes, S, 0, N-1));
	printf ("\nMax Value 2 mem = %d.\n", Max[0][S]);
	printf ("\nMax Value without recursion = %d.\n", knapsack_wihtout_recursion());
	s = S;
	/* To print which Values are Taken */
        for (i=0; i<=N; i++) {
                if (Keep[i][s]) {
                    printf ("Take item with Index %d Value %d. \n", i, Values[i]);
		    s = s - Sizes[i];
                }
        }
	return 0;
}
