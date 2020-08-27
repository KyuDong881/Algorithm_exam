#include <stdio.h>
#pragma warning(disable:4996)
int dp[1001];

int min(int a, int b) {
	return a > b ? b : a;
}

int main(void) {

	int N;
	int ans;
	scanf("%d", &N);
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= N; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] = dp[i] % 10007;
	}

	ans = dp[N] % 10007;
	printf("%d\n", dp[N]);
	return 0;
}
