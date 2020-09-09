#include <iostream>
#include <algorithm>
using namespace std;

#define A 3
#define B 5
int ans1, ans2;
unsigned int dp[91];
int main()
{
	int n;
	cin >> n;

	long long int fi0 = 0;
	long long int fi1 = 1;
	long long int ans;
	if (n < 2) ans = 1;
	else
	{
		for (int i = 2; i < n + 1; i++)
		{
			ans = fi0 + fi1;
			fi0 = fi1;
			fi1 = ans;
		}
	}
	

	cout << ans;

	return 0;

}