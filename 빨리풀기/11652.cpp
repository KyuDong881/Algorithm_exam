#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<long long> v;
int answer = 1;
long long ans;
void Input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		long long a;
		cin >> a;
		v.push_back(a);
	}
}

void Solve()
{
	int cnt = 1;
	
	sort(v.begin(), v.end());
	ans = v[0];
	for (int i = 1; i < n; i++)
	{
		if (v[i] == v[i - 1])
		{
			cnt++;
		}
		else
		{
			cnt = 1;
		}

		if (answer < cnt)
		{
			answer = cnt;
			ans = v[i];
		}

	}

	cout << ans;
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