#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;

int dx[8] = { 0,1,1,1,0,-1,-1,-1};
int dy[8] = { 1,1,0,-1,-1,-1,0,1 };

#define MAX 50;
int width = -1;
int height = -1;
int map[51][51];
int vis[51][51] = { 0, };

queue<pair<int, int> > q;

int ans = 0;


void bfs(int x, int y)
{
	vis[x][y] = 1;
	q.push(make_pair(x, y));
	while (!q.empty())
	{
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			
			if (nx >= 0 && ny >= 0 && nx < height && ny < width)
			{
				if (vis[nx][ny] == 0)
				{
					if (map[nx][ny] == 1)
					{
						vis[nx][ny] = 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
}

int main()
{
	while (1)
	{
		cin >> width >> height;

		if (width == 0 && height == 0) break;

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (vis[i][j] == 0 && map[i][j] == 1)
				{
					bfs(i, j);
					ans++;
				}
			}
		}
		cout << ans <<'\n';
		ans = 0;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				map[i][j] = 0;
				vis[i][j] = 0;
			}
		}
	}
	return 0;
}