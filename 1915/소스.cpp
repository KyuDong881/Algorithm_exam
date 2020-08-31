#include <cstdio>
#include <algorithm>
using namespace std;
int dp[1001][1001] = { 0, };
int map[1001][1001] = { 0, };
#pragma warning(disable:4996)

int max(int a, int b)
{
	return a > b ? a : b;
}


int main()
{
	
	int n, m, max;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	max = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (map[i][j] == 0) continue;
			else if (map[i - 1][j - 1] > 0 && map[i][j - 1] > 0 && map[i - 1][j] > 0)
			{
				map[i][j] = min(map[i - 1][j], min(map[i - 1][j - 1], map[i][j - 1])) + 1;
				if (map[i][j] > max)
					max = map[i][j];
			}
			else continue;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] > max) max = map[i][j];
		}
	}


	printf("%d", max*max);

	return 0;
}