#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define X first 
#define Y second
using namespace std;
char rgb[101][101] = { 'A', };
char rb[101][101] = { 'A', };
int board[101][101] = { 0, };
int vis[101][101] = { 0, };
int vis1[101][101] = { 0, };

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int dp[1001][1001] = { 0, };
int map[1001][1001] = { 0, };

queue<pair<int, int>> q;
int n, m;
int ans_sum = -1;
int ans1 = 0;
int ans2 = 0;
#pragma warning(disable:4996)

int tempMap[9][9] = { 0, };

int test = 0;

void bfs1(int i,int j)
{
	q.push(make_pair(i, j));
	vis[i][j] = 1;
	while (!q.empty())
	{
		int xx = q.front().X;
		int yy = q.front().Y;
		q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = xx + dx[dir];
			int ny = yy + dy[dir];
			if (nx < 0 || ny<0 || nx >= n || ny >= n) continue;
			if (vis[nx][ny] == 1) continue;
			if (rgb[xx][yy] == rgb[nx][ny])
			{
				vis[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
	ans1++;
}

void bfs2(int i, int j)
{
	q.push(make_pair(i, j));
	vis1[i][j] = 1;
	while (!q.empty())
	{
		int xx = q.front().X;
		int yy = q.front().Y;
		q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = xx + dx[dir];
			int ny = yy + dy[dir];
			if (nx < 0 || ny<0 || nx >= n || ny >= n) continue;
			if (vis1[nx][ny] == 1) continue;
			if (rb[nx][ny] == rb[xx][yy]) 
			{
				vis1[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
	ans2++;
}


void makeWall(int count)
{
	if (count == 3)
	{
		//bfs();
		return;
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (tempMap[i][j] == 0)
			{
				tempMap[i][j] = 1;
				makeWall(count + 1);
				tempMap[i][j] = 0;
			}
		}
	}

}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> rgb[i][j];
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			rb[i][j] = rgb[i][j];
			if (rgb[i][j] == 'G') rb[i][j] = 'R';
			if (vis[i][j] == 0) {
				bfs1(i, j);
			}
		}
	}


	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (vis1[i][j] == 0) bfs2(i, j);
		}
	}
	
	


	if (ans_sum < 0) ans_sum = 0;
	cout << ans1 << ' ' << ans2;



	return 0;
}