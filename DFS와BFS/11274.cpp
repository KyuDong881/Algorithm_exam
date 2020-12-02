#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int N, M;
vector<int> v[1001];
int visit[1001] = { 0, };
queue<int> q;
int s, e;
int answer = 0;
void Input()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}
}

void bfs(int start)
{
	visit[start] = 1;
	q.push(start);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i<v[cur].size(); i++)
		{
			if (visit[v[cur][i]] == 1) continue;
			visit[v[cur][i]] = 1;
			q.push(v[cur][i]);
		}
	}
	answer++;
}

void Solve()
{
	for (int i = 1; i <= N; i++)
	{
		if (visit[i] == 1) continue;
		bfs(i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	Input();
	Solve();
	cin.tie(NULL);
	cout.tie(NULL);
	cout << answer;
}