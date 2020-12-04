#include <iostream>
#include <vector>

using namespace std;
int n,k;
vector<int>v;
int answer = 0;
void Input()
{
	cin >> n >>k;
	for (int i = 0; i < n; i++)
	{
		int cost;
		cin >> cost;
		v.push_back(cost);
	}

}

void Solve()
{
	reverse(v.begin(), v.end());
	int cur = 0;
	int idx = 0;
	int remain = k;
	while (1)
	{
		if (v[idx] > remain)
		{
			idx++;
			continue;
		}
		remain = remain - v[idx];
		answer++;
		if (remain == 0) break;
	}

	cout << answer;
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