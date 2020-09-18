#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#pragma warning(disable:4996)
using namespace std;

int n, m;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int map[101][101];
int visit[101][101];

int ans = 0;

queue<pair <int, int>>q;

void bfs(int x, int y)
{
	visit[x][y] = 1;
	q.push(make_pair(x, y));

	while (!q.empty())
	{
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = xx + dx[dir];
			int ny = yy + dy[dir];
			
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visit[nx][ny] > 0 || map[nx][ny]==0) continue;

			q.push(make_pair(nx, ny));
			visit[nx][ny] = visit[xx][yy] + 1;
		}
	}
	return;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	bfs(0, 0);

	cout << visit[n - 1][m - 1];
	


}