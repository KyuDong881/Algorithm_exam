#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int answer = 0;
int N, M;
int board[501][501];
queue<pair<int, int>> q;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void Input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}
}

void bfs(int y,int x)
{
	visit[y][x] = 1;
	q.push(make_pair(y, x));
	while (!q.empty())
	{
		int yy = q.front().first;
		int xx = q.front().second;
		if (yy == N - 1 && xx == M - 1) answer++;
		q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int ny = yy + dy[dir];
			int nx = xx + dx[dir];
			
			if (ny >= M || nx >= N | ny < 0 || nx < 0) continue;
			if (visit[ny][nx] == 1) continue;
			if (board[yy][xx] >= board[ny][nx]) continue;
			visit[ny][nx] = 1;
			q.push(make_pair(ny, nx));
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Input();
	bfs(0, 0);
	cout << answer;
}