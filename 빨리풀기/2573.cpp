#include <iostream>
#include <queue>
using namespace std;

int n, m;
int ans = 0;

int board[301][301] = { 0, };
int visit[301][301] = { 0, };
int temp[301][301] = { 0, };
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };

queue<pair<int, int>> q;

void Input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
}
bool Check_two()
{
	bool two = false;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visit[i][j] = 0;

	
	int y = q.front().first;
	int x = q.front().second;
	visit[y][x] = 1;

	queue<pair<int, int>> mq;
	mq.push(make_pair(y, x));

	while (!mq.empty())
	{
		int yy = mq.front().first;
		int xx = mq.front().second;
		mq.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			if (ny >= n || nx >= m || ny < 0 || nx < 0) continue;
			if (visit[ny][nx] == 1 || board[ny][nx] == 0) continue;
			visit[ny][nx] = 1;
			mq.push(make_pair(ny, nx));
		}
	}

	int cnt = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (visit[i][j] == 1) cnt++;

	if (cnt != q.size()) two = true;

	return two;
}

void Melt()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (temp[i][j] > 0)
			{
				board[i][j] -= temp[i][j];
				if (board[i][j] < 0) board[i][j] = 0;
				temp[i][j] = 0;
			}
		}
	}

}

void Solve()
{
	while (1)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] > 0)
				{
					q.push(make_pair(i, j));
				}
			}
		}
		if (q.empty())
		{
			cout << 0;
			return;
		}

		if (Check_two())
		{
			cout << ans;
			return;
		}

		while (!q.empty())
		{
			int yy = q.front().first;
			int xx = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = yy + dy[i];
				int nx = xx + dx[i];
				if (ny >= n || nx >= m || ny < 0 || nx < 0) continue;
				if (board[ny][nx] > 0) continue;
				if (board[ny][nx] == 0)
					temp[yy][xx]++;
			}
		}
		Melt();
		ans++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Input();
	Solve();

	return 0;

}