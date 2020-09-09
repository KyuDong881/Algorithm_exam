#include <iostream>
#include <algorithm>
using namespace std;

#define A 3
#define B 5
int ans1, ans2;
int dp[15][15];
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (j == 1) dp[i][j] = 1;
			if (i == 0) dp[i][j] = j;
		}
	}
	for (int i = 1; i < 15; i++)
	{
		for (int j = 2; j < 15; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	int k, n;
	while (1)
	{
		cin >> k >> n;
		cout << dp[k][n];
		t--;
		if (t == 0) break;
		cout << '\n';
	}

	return 0;

}