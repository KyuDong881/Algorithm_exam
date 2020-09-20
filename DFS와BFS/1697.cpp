#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#pragma warning(disable:4996)
using namespace std;

int n, m;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int map[1001][1001];
int visit[1001][1001];
int dist[1001][1001];
int ans = 0;
int tmp = 0;
int vis[100001] = { 0, };

queue<pair <int, int>>q;

int bfs(int start)
{
	q.push(make_pair(start, 0));

	while (!q.empty())
	{
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		
		if (xx < 0 || xx>100001) continue;
		if (vis[xx] == 1) continue;
		vis[xx] = 1;

		if (xx == m) return yy;

		q.push(make_pair(xx * 2, yy + 1));
		q.push(make_pair(xx + 1, yy + 1));
		q.push(make_pair(xx - 1, yy + 1));

	}

}

int main()
{
	cin >> n >> m;
	ans = bfs(n);

	cout << ans;

	return 0;
}