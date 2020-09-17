#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#pragma warning(disable : 4996)

using namespace std;
int vis[101][101] = { 0, };
int board[101][101] = { 0, };

int visit[101] = { 0, };
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };

queue<pair <int, int>> q;
queue<int> q2;

int n, m, k;
int ans = 0;

void bfs(int x,int y)
{
	vis[x][y] = 1;
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
			
			if (nx < 0 || ny<0 || nx >= n || ny>=m) continue;
			if (vis[nx][ny] == 1) continue;
			if (board[nx][ny] == 0) continue;
			vis[nx][ny] = 1;

			q.push({ nx,ny });
		}
	}

}

int main()
{
	int tc_num;
	int a, b;
	cin >> tc_num;
	while (1)
	{
		if (tc_num == 0) break;
		cin >> n >> m >> k;
		for (int i = 0; i < k; i++)
		{
			cin >> a >> b;
			board[a][b] = 1;
		}
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (vis[i][j] == 1 || board[i][j] == 0) continue;
				else {
					bfs(i, j);
					ans++;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				vis[i][j] = 0;
				board[i][j] = 0;
			}
		}
		cout << ans << endl;
		ans = 0;
		tc_num--;
	}
	return 0;

}
