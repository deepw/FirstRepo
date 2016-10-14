
#include <stdio.h>

int robber_max (int Money[], int n) {

	int Value[n+1];
	Value[0] = 0;
	Value[1] = Money[0];

	for (i=2; i<=n; i++) {
		Value[i] = max (Money[i] + Value[i-2], Value[i-1]);
	}

	return Value[n];
}

int robber_max (int Money[], int n) {
	int Value = 0;
	int back = Money[0];
	int back2 = 0;

	for (i=2; i<=n; i++) {
		value = max (Money[i-1] + back2, back);
		back2 = back;
		value = back;
	}
	return value;
}

