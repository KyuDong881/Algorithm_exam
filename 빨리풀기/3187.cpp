#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<pair<int,pair<int, int>>> animal;
int remain_w = 0;
int remain_s = 0;

char board[251][251];
int visit[251][251] = { 0, };
int R, C;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int area_num = 1;


void Input()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'v') animal.push_back(make_pair(0,make_pair(i, j)));
			else if (board[i][j] == 'k') animal.push_back(make_pair(1, make_pair(i, j)));
		}
	}
		

}

void bfs(int r, int c, bool vk)
{
	if (visit[r][c] != 0) return;
	int wolfs = 0;
	int sheeps = 0;

	if (vk) wolfs++;
	else sheeps++;

	visit[r][c] = area_num;
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	
	while (!q.empty())
	{
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
			if (board[ny][nx] == '#') continue;
			if (visit[ny][nx] > 0) continue;
			
			if (board[ny][nx] == 'v') wolfs++;
			if (board[ny][nx] == 'k') sheeps++;

			visit[ny][nx] = area_num;
			q.push(make_pair(ny, nx));
		}
	}
	if (wolfs >= sheeps) remain_w += wolfs;
	else remain_s += sheeps;
	area_num++;
}

void Solve()
{
	bool vk;
	for (int i = 0; i < animal.size(); i++) {
		if (animal[i].first == 0) vk = true;
		else vk = false;
		bfs(animal[i].second.first, animal[i].second.second, vk);
	}

	cout << remain_s << " " << remain_w;

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


