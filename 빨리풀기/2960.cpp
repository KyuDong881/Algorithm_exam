#include <iostream>
using namespace std;

int n, k;
int ans = 0;
bool check[1001];
void Input()
{
	cin >> n >> k;
}

void Solve()
{
	for (int i = 2; i <= n; i++)
	{
		if (check[i]) continue;
		ans++;
		if (ans == k)
		{
			cout << i;
			return;
		}
		for (int j = i+i; j <= n; j = j+i)
		{
			if (check[j]) continue;
			check[j] = true;
			ans++;
			if (ans == k)
			{
				cout << j;
				return;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Input();
	Solve();

	return 0;

}