#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#pragma warning(disable:4996)
using namespace std;
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };

int n, m;
int map[1001][1001];
int vis[1001][1001][2];
int block = 1;

queue <pair< pair<int, int>,int>>q;

int bfs(int x,int y)
{
	vis[x][y][block] = 1;
	q.push(make_pair(make_pair(x, y),block));
	
	while (!q.empty())
	{
		int xx = q.front().first.first;
		int yy = q.front().first.second;
		int block = q.front().second;

		q.pop();
		if (xx == n - 1 && yy == m - 1) return vis[xx][yy][block];
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = xx + dx[dir];
			int ny = yy + dy[dir];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		
			if (map[nx][ny] == 1 && block == 0) continue;
			if (map[nx][ny] == 1 && block == 1)
			{
				vis[nx][ny][block - 1] = vis[xx][yy][block] + 1;
				q.push(make_pair(make_pair(nx, ny), block-1));
			}

			if (map[nx][ny] == 0 && vis[nx][ny][block]==0)
			{
				vis[nx][ny][block] = vis[xx][yy][block] + 1;
				q.push(make_pair(make_pair(nx, ny), block));
			}

		}
	}
	return -1;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &map[i][j]);
	
	cout << bfs(0, 0);

}