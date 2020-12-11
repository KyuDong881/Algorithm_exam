#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/* 
첫째 줄에 도시의 개수 N, 도로의 개수 M, 거리 정보 K, 출발 도시의 번호 X가 주어진다. 
(2 ≤ N ≤ 300,000, 1 ≤ M ≤ 1,000,000, 1 ≤ K ≤ 300,000, 1 ≤ X ≤ N) 둘째 줄부터 M개의 줄에 걸쳐서 두 개의 자연수 A, B가 공백을 기준으로 구분되어 주어진다. 
이는 A번 도시에서 B번 도시로 이동하는 단방향 도로가 존재한다는 의미다. 
(1 ≤ A, B ≤ N) 단, A와 B는 서로 다른 자연수이다.
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