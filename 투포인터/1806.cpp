#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#pragma warning(disable:4996)
using namespace std;


int arr[100001];
int n, s;
int ans = INT_MAX;

int solve()
{
	int left = 0;
	int right = 0;
	int sum = 0;

	while (1)
	{

		if (sum >= s)
		{
			ans = min(ans, right - left);
			sum -= arr[left];
			left++;
		}
		else if (right == n) break;
		else
		{
			sum += arr[right];
			right++;
		}

	}

	if (ans == INT_MAX)
		return 0;
	else
		return ans;
}

int main()
{
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("%d", solve());
}