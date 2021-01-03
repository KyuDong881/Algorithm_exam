#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n;
int Parent[1001];
vector<pair<int,pair<int, int>>> info;
long long answer = 0;


void Input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int cost;
			cin >> cost;
			info.push_back(make_pair(cost, make_pair(i, j)));
		}
	}

	for (int i = 1; i <= n; i++)
		Parent[i] = i;

}

int find_parent(int x)
{
	if (x==Parent[x]) return x;
	else return Parent[x] = find_parent(Parent[x]);
}

void Union(int x, int y)
{
	int rootx = find_parent(x);
	int rooty = find_parent(y);
	if (rootx != rooty)
		Parent[rooty] = rootx;
}

bool check_union(int x, int y)
{
	if (find_parent(x) == find_parent(y))
		return true;
	else return false;
}



void Solve()
{
	sort(info.begin(), info.end());
	int cnt = 0;
	for (int i = 0; i < info.size(); i++)
	{
		if (cnt == n - 1) break;
		int cost = info[i].first;
		if (cost == 0) continue;
		int start = info[i].second.first;
		int dest = info[i].second.second;
		if (check_union(start, dest)==false)
		{
			Union(start, dest);
			answer += cost;
			cnt++;
		}
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