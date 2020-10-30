#include <iostream>
#include <algorithm>
using namespace std;
int n;
int ans;

int solve(int k)
{
	int n = k;
	int a, b, c;
	int ans = 0;
	bool check = false;
	if (k >=100)
	{
		while (1)
		{
			if (n < 100) return ans+99;
			a = n / 100;
			b = (n - a * 100) / 10;
			c = n - ((a * 100) + (b * 10));
			if (a - b == b - c)
			{
				ans++;
			}
			n--;
		}
	}
	else return k;

}

int main()
{
	cin >> n;
	ans = solve(n);
	cout << ans;
}