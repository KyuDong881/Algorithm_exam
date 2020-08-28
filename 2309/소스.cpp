#include <cstdio>
#include <algorithm>
using namespace std;
int dp[301];
int stairs[301];
#pragma warning(disable:4996)

int max(int a, int b)
{
	return a > b ? a : b;
}


int main()
{
	int bf[9];
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &bf[i]);
		sum = sum + bf[i];
	}
	
	sort(bf, bf + 9);

	for (int i = 0; i < 8; i++)
	{
		for (int j = i+1; j < 9; j++)
		{
			if (sum - (bf[i] + bf[j]) == 100)
			{
				for (int k = 0; k < 9; k++)
				{
					if ((k == i) || (k == j)) continue;
					else printf("%d\n", bf[k]);
				}
				return 0;
			}
		}
	}
	

	return 0;
}