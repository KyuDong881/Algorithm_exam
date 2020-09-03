#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define X first 
#define Y second
using namespace std;
int board[500][500] = { 0, };
int vis[500][500] = { 0, };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int dp[10001] = { 0, };
int map[1001][1001] = { 0, };
queue<pair<int, int>> q;
int n, m;
int ans_sum = -1;
int ans = 0;
#pragma warning(disable:4996)


void bfs(int x, int y)
{
	vis[x][y] = 1;
	q.push(make_pair(x,y));
	int sum = 1;
	while (!q.empty())
	{
		int xx = q.front().X;
		int yy = q.front().Y;
		q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = xx + dx[dir];
			int ny = yy + dy[dir];
			if (nx < 0 || ny<0 || nx >= n || ny > m) continue;
			if (vis[nx][ny] || board[nx][ny] != 1) continue;
			vis[nx][ny]=1;
			q.push({ nx,ny });
			++sum;
		}
	}
	ans_sum = max(sum, ans_sum);
	
}

int main()
{
	int grape[10001] = { 0, };
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&grape[i]);
	}

	dp[0] = grape[0];
	dp[1] = grape[0] + grape[1];
	dp[2] = max(grape[1] + grape[2], max(grape[0] + grape[1], grape[0] + grape[2]));

	for (int i = 3; i < n; i++)
	{
		dp[i] = max(dp[i - 3] + grape[i - 1] + grape[i], dp[i - 2] + grape[i]);
		dp[i] = max(dp[i - 1], dp[i]);
	}
	printf("%d", dp[n-1]);
	return 0;
}