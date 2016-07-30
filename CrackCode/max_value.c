#include <stdio.h>

int max_val(int val[], int wt[], int m, int W) 
{
	int i = 0, max=0, submax=0;
	if (W == 0)
		return 0;

	for (i=0; i<m; i++) {
		if (wt[i] <= W) {
			submax = val[i] + max_val (val, wt, m, W-wt[i]);

			if (submax > max) {
				printf ("Use val=%d.\n", val[i]);
				max = submax;
			}
		}
	}

	return max;
}


// Driver program to test above function
int main()
{
    int val[] =  {9, 6, 5, 1};
    int wt[] =  {3, 2, 2, 1};
    int W = 7;
    int m = sizeof(val)/sizeof(val[0]);
    printf ("Max Val=%d.\n", max_val(val, wt, m, W)); 
    return 0;
}


/*

Look at Various Column Based Optimization Techniques
Compression
Tuple Reconstruction
Join Optimization
Projections
Others






wieghts[]
values[]
DP[w+1];
DP[0]=0;
W[0]=w;
W[w+1]


for (i=0; i<w; i++) {
	if (j=0; j<Ntypes; j++) {

	if (w-W[i-1] <= Weight[j])
		DP[i] = DP[i-1]+Value[j];








return DP[w]



	Weights[]
	Values[]


	DP[i]= 



	knapsack (int weights[N], int Values[N], int w) {
		if (w==0)
			return 0;

		if 


*/
