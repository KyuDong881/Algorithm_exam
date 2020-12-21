#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int n, m, k;
vector<int> area;
int board[101][101];
int visit[101][101];
queue<pair<int, int>> q;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int answer = 0;


void Input()
{
	cin >> n >> m >> k; //n개중 m개를 중복없이 출력
	for (int i = 0; i < k; i++)
	{
		int x1, x2, y1, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		for (int j = y1; j < y2; j++)
		{
			for (int s = x1; s < x2; s++)
			{
				board[j][s] = 1;
			}
		}
	}
}
void bfs(int i, int j)
{
	answer++;
	visit[i][j] = answer;
	q.push(make_pair(i, j));
	while (!q.empty())
	{
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int ny = yy + dy[dir];
			int nx = xx + dx[dir];
			if (ny >= m || nx >= n || ny < 0 || nx < 0) continue;
			if (board[ny][nx] == 1 || visit[ny][nx]>0) continue;
			visit[ny][nx] = answer;
			q.push(make_pair(ny, nx));
		}
	}
	int size = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visit[i][j] == answer) size++;
		}
	}
	area.push_back(size);

}
void Solve(int cnt)
{
	sort(area.begin(), area.end());
	cout << answer << "\n";
	for (int i = 0; i < area.size(); i++)
	{
		cout << area[i] << " ";
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Input();
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visit[i][j] >0 || board[i][j] == 1) continue;
			bfs(i, j);
		}

	}
	Solve(0);

	return 0;
}