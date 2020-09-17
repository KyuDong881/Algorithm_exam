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

int ans = 0;
int number, link;
int com1, com2;

int ans_arr[626];
int ans_num = 1;
int ans_index = 0;

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
			
			if (nx < 0 || ny<0 || nx >= number || ny>=number) continue;
			if (vis[nx][ny] == 1) continue;
			if (board[nx][ny] == 0) continue;
			vis[nx][ny] = 1;
			ans_num++;
			q.push({ nx,ny });
		}
	}
	ans_arr[ans_index] = ans_num;
	ans_index++;
	ans_num = 1;
}

int main()
{
	cin >> number;
	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < number; j++)
		{
			scanf("%1d", &board[i][j]);
		}
	}

	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < number; j++)
		{
			if (vis[i][j] == 0 && board[i][j]==1)
			{
				bfs(i, j);
			}
		}
	}

	sort(ans_arr, ans_arr + ans_index);
	cout << ans_index << '\n';
	for (int i = 0; i < ans_index-1; i++)
	{
		cout << ans_arr[i]<<endl;
		
	}
	if (ans_arr[ans_index - 1] != 0) cout << ans_arr[ans_index - 1];

	return 0;

}
