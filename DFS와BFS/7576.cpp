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

queue<pair <int, int>>q;

void bfs()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 1)
			{
				visit[i][j] = 1;
				q.push(make_pair(i, j));
			}
		}
	}

	while (!q.empty())
	{
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = xx + dx[dir];
			int ny = yy + dy[dir];
			
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (map[nx][ny] == -1) visit[nx][ny] = -1;
			if (visit[nx][ny] > 0 || map[nx][ny]<0) continue;

			q.push(make_pair(nx, ny));
			visit[nx][ny] = visit[xx][yy]+1;
		}
	}

	return;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >>map[i][j];
			if (map[i][j] == -1) visit[i][j] = -1;
		}
	}
	bfs();
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visit[i][j] == 0)
			{
				tmp = -1;
				break;
			}
			else ans = max(ans, visit[i][j]);
		}
	}
	if (tmp < 0) cout << tmp;
	else cout << ans - 1;// 처음 자기자신 visit을 1로 했음
	


}