#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k, l;
int board[101][101] = { 0, };
queue<pair<int, char>> cmd;
int dy[5] = { 0,0,0,1,-1 };
int dx[5] = { 0,1,-1,0,0 };
queue<pair<int, int>> tail;

void Input()
{
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> y >> x;
		board[y][x] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int x;
		char c;
		cin >> x >> c;
		cmd.push(make_pair(x, c));
	}

}

int ChangeDir(int cdir, char chadir)
{
	if (cdir == 1)
	{
		if (chadir == 'L')
		{
			return 4;
		}
		else return 3;
	}
	else if (cdir == 2)
	{
		if (chadir == 'L')
		{
			return 3;
		}
		else return 4;
	}
	else if (cdir == 3)
	{
		if (chadir == 'L')
		{
			return 1;
		}
		else return 2;
	}
	else
	{
		if (chadir == 'L')
		{
			return 2;
		}
		else return 1;
	}
}

void bfs()
{
	queue<pair<pair<int, int>, int>>q;

	q.push({{ 1,1 }, 1});
	int time = 0;
	int tsy = 1;
	int tsx = 1;
	tail.push(make_pair(tsy, tsx));
	while (!q.empty())
	{
		int hx = q.front().first.second;
		int hy = q.front().first.first;
		
		int ty = tail.front().first;
		int tx = tail.front().second;

		int cdir = q.front().second;
		q.pop();
		cout << hy << "," << hx <<","<<time<<","<<cdir <<"\n";
		if (!cmd.empty())
		{
			if (time == cmd.front().first)
			{
				char chadir = cmd.front().second;
				cout << "¹æÇâ : " << chadir << "\n";
				cdir = ChangeDir(cdir, chadir);
				cmd.pop();
			}
		}
		int ny = hy + dy[cdir];
		int nx = hx + dx[cdir];
		time++;
		if (ny<1 || nx<1 || ny>n || nx>n) break;
		if (board[ny][nx] == 2) break;
		
		if (board[ny][nx] == 0)
		{
			board[ny][nx] = 2;
			board[ty][tx] = 0;
			tail.pop();
			tail.push(make_pair(ny, nx));
			q.push(make_pair(make_pair(ny, nx),cdir));
		}
		else if (board[ny][nx] == 1)
		{
			board[ny][nx] = 2;
			q.push(make_pair(make_pair(ny, nx), cdir));
			tail.push(make_pair(ny, nx));
		}

	}
	cout << time;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Input();
	bfs();
}