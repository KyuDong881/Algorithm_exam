#include <stdio.h>
#pragma warning(disable:4996)
int Dp[1000001];
int Dp2[1000001];

int min(int a, int b) {
	return a > b ? b : a;
}

int main(void) {

	int N;
	scanf("%d", &N);

	Dp[1] = 0;
	Dp2[1] = -1;

	for (int i = 2; i <= N; ++i)
	{
		Dp[i] = Dp[i - 1] + 1;
		Dp2[i] = i - 1;
		if (i % 2 == 0) {
			if (Dp[i / 2] + 1 < Dp[i]) {
				Dp[i] = Dp[i / 2] + 1;
				Dp2[i] = i / 2;
			}
			else {
				Dp[i] = Dp[i];
				Dp2[i] = Dp2[i];
			}
		}
		if (i % 3 == 0) {
			if (Dp[i / 3] + 1 < Dp[i]) {
				Dp[i] = Dp[i / 3] + 1;
				Dp2[i] = i / 3;
			}
			else {
				Dp[i] = Dp[i];
				Dp2[i] = Dp2[i];
			}
		}
	}

	printf("%d\n", Dp[N]);
	while (N != -1) {
		printf("%d ", N);
		N = Dp2[N];
	}
	return 0;
}
