#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
bool check[21] = { false, };
int info[21][21];
int ans = 99999;


void Input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> info[i][j];
		}
	}
}


void solve()
{
	vector<int> team1;
	vector<int> team2;
	for (int i = 0; i < n; i++)
	{
		if (check[i])
		{
			team1.push_back(i);
		}
		else team2.push_back(i);
	}
	int sum1 = 0;
	int sum2 = 0;
	
	for (int i = 0; i < team1.size(); i++)
		for (int j = 0; j < team1.size(); j++)
			sum1 += info[team1[i]][team1[j]];

	for (int i = 0; i < team2.size(); i++)
		for (int j = 0; j < team2.size(); j++)
			sum2 += info[team2[i]][team2[j]];

	int diff = abs(sum1 - sum2);
	ans = min(ans, diff);
}

void bt(int idx, int cnt)
{
	if (cnt == n / 2)
	{
		solve();
		return;
	}

	for (int i = idx; i < n; i++)
	{
		if (check[i]) continue;
		check[i] = true;
		bt(i, cnt + 1);
		check[i] = false;
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Input();
	bt(0, 0);
	cout << ans;
}
