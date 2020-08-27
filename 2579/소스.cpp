#include <stdio.h>
#include <algorithm>
int dp[301];
int stairs[301];
#pragma warning(disable:4996)

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int i = 1;
	int N;
	scanf("%d", &N);
	while (i <= N)
	{
		scanf("%d", &stairs[i]);
		i++;
	}
	dp[1] = stairs[1];
	dp[2] = stairs[1] + stairs[2];
	dp[3] = max(dp[1] + stairs[3], stairs[2] + stairs[3]);
	for (int j = 4; j <= N; j++)
	{
		dp[j] = max(dp[j - 2] + stairs[j], dp[j - 3] + stairs[j-1] + stairs[j]);
	}
	printf("%d", dp[N]);
	return 0;
}