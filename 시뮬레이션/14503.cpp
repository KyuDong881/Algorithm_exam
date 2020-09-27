#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int vis[51][51] = { 0, };
int board[51][51] = { 0, };
int direct[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };


queue<pair<pair <int, int>, int>> q;
queue<int> q2;

int n, m;
int r, c, d;
int ans = 0;

void bfs(int y, int x, int dir)
{
	vis[y][x] = 1;
	q.push(make_pair(make_pair(y, x), dir));
	ans = 1;
	while (!q.empty())
	{
		int yy = q.front().first.first;
		int xx = q.front().first.second;
		int yxdir = q.front().second;
		q.pop();
		int check = 0;

		for (int dir = 0; dir < 4; dir++)
		{
			int n_dir = (yxdir + (3 - dir)) % 4;
			int ny = yy + direct[n_dir][0];
			int nx = xx + direct[n_dir][1];
			if (ny > 0 && nx > 0 && ny < n && nx < m)
			{
				if (board[ny][nx] == 0 && vis[ny][nx] == 0)
				{
					check = 1;
					vis[ny][nx] = 1;
					ans++;
					q.push(make_pair(make_pair(ny, nx), n_dir));
					break;
				}
			}
		}

		/*int rot_count = 3;
		while (1)
		{
			if (n_dir > 0)
			{
				int ny = yy + direct[n_dir - 1][0];
				int nx = xx + direct[n_dir - 1][1];
				if (ny > 0 && nx > 0 && ny < n && nx < m)
				{
					if (board[ny][nx] == 0 && vis[ny][nx] == 0)
					{
						check = 1;
						vis[ny][nx] = 1;
						ans++;
						q.push(make_pair(make_pair(ny, nx), n_dir - 1));
						break;
					}
				}

			}
			else
			{
				int ny = yy + direct[n_dir + 3][0];
				int nx = xx + direct[n_dir + 3][1];
				if (ny > 0 && nx > 0 && ny < n && nx < m)
				{
					if (board[ny][nx] == 0 && vis[ny][nx] == 0)
					{
						check = 1;
						vis[ny][nx] = 1;
						ans++;
						q.push(make_pair(make_pair(ny, nx), n_dir + 3));
						break;
					}
				}
			}
			if (n_dir == 0) n_dir = n_dir + 3;
			else n_dir = n_dir - 1;
			rot_count--;
			if (check == 0 && rot_count == 0) break;
		}*/

		if (check == 0)
		{
			int back_y = yy - direct[yxdir][0];
			int back_x = xx - direct[yxdir][1];
			if (board[back_y][back_x] == 1) return;
			else
			{
				q.push(make_pair(make_pair(back_y, back_x), yxdir));
			}
		}

	}

	return;

}


int main()
{
	cin >> n >> m >> r >> c >> d;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	bfs(r, c, d);

	cout << ans;
	return 0;

}
