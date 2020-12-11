#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/* 
ù° �ٿ� ������ ���� N, ������ ���� M, �Ÿ� ���� K, ��� ������ ��ȣ X�� �־�����. 
(2 �� N �� 300,000, 1 �� M �� 1,000,000, 1 �� K �� 300,000, 1 �� X �� N) ��° �ٺ��� M���� �ٿ� ���ļ� �� ���� �ڿ��� A, B�� ������ �������� ���еǾ� �־�����. 
�̴� A�� ���ÿ��� B�� ���÷� �̵��ϴ� �ܹ��� ���ΰ� �����Ѵٴ� �ǹ̴�. 
(1 �� A, B �� N) ��, A�� B�� ���� �ٸ� �ڿ����̴�.
*/

int n, m, k, x;
vector<int> info[300001];
vector<int> answer;
queue<pair<int, int>> q;
int visit[300001];

void Input()
{
	cin >> n >> m >> k >> x;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		info[a].push_back(b);
	}
}

void Solve()
{
	visit[x] = 1;
	bool check = false;
	q.push(make_pair(x,0));

	while (!q.empty())
	{
		int cur = q.front().first;
		int dist = q.front().second;
		q.pop();
		if (dist == k)
		{
			check = true;
			answer.push_back(cur);
			continue;
		}
		for (int i = 0; i <info[cur].size(); i++)
		{
			int ncity = info[cur][i];
			if (visit[ncity] == 1) continue;
			visit[ncity] = 1;
			q.push(make_pair(ncity,dist+1));
		}
	}

	if (check)
	{
		sort(answer.begin(), answer.end());
		for (int i = 0; i < answer.size(); i++)
			cout << answer[i] << "\n";
	}
	else cout << -1;

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