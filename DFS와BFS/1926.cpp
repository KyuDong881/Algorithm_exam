#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int board[501][501];
int vis[501][501];
int n, m;
int num = 0;
int ans_size = 0;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

queue<pair<int, int>>q;

void bfs(int i,int j)
{
	vis[i][j] = 1;
	int tmp_size = 1;
	q.push(make_pair(i, j));
	while (!q.empty())
	{
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = xx + dx[dir];
			int ny = yy + dy[dir];

			if (ny >= n || nx >= m || nx < 0 || ny < 0) continue;
			if (board[ny][nx] == 0 || vis[ny][nx] == 1) continue;

			vis[ny][nx] = 1;
			q.push(make_pair(ny, nx));
			tmp_size++;
		}
	}
	num++;
	ans_size = max(tmp_size, ans_size);
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 1 && vis[i][j] == 0)
				bfs(i, j);
		}
	}
	cout << num <<"\n"<< ans_size;

}