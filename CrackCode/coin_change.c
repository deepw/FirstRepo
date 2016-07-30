#include<stdio.h>
#include<string.h>

int result[4];
int print_demo(int Coins[], int N, int Value, int curValue, int cpos, int pos) 
{
	int i =0, j=0;

	if (Value == 0)
		return 0;

	if (curValue == Value) {
		for (j=0; j<pos; j++) {
			printf ("%d\t", result[j]);
		}
		printf ("\n");
		return 0;
	}

	for (i=cpos; i<N; i++) {
		if (Coins[i] <= Value - curValue) {
			result[pos] = Coins[i];
			print_demo (Coins, N, Value, curValue + Coins[i], i, pos+1);
		}
	}

	return 0;
}

int main ()
{
	int Coins[] = {1, 2, 3};
	print_demo (Coins, sizeof(Coins)/sizeof(Coins[0]), 4, 0, 0, 0);
	return 0;
}

