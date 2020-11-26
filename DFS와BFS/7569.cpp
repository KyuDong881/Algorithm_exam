#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int tomato[101][101][101] = { 0, };
int visit[101][101][101] = { 0, };
int M, N, H;

int time = 0;

vector<pair<int, pair<int, int>>> start;

void Input()
{
	cin >> M >> N >> H;
	for (int z = 0; z < H; z++)
	{
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				cin >> tomato[z][y][x];
				if (tomato[z][y][x] == 1)
				{
					start.push_back(make_pair(z, make_pair(y, x)));
				}
				else if (tomato[z][y][x] == -1) visit[z][y][x] = -1;
			}
		}
	}
}

void Solution()
{
	bool check = true;
	queue<pair<int, pair<int, int>>> q;
	for (int i = 0; i < start.size(); i++)
	{
		q.push(start[i]);
		int z = start[i].first;
		int y = start[i].second.first;
		int x = start[i].second.second;

		visit[z][y][x] = 1;
	}
	while (!q.empty())
	{
		int cz = q.front().first;
		int cy = q.front().second.first;
		int cx = q.front().second.second;
		q.pop();
		for (int dir = 0; dir < 6; dir++)
		{
			int nz = cz + dz[dir];
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			
			if (nz < 0 || ny < 0 || nx < 0 || nz >= H || ny >= N || nx >= M) continue;
			if (visit[nz][ny][nx] > 0|| tomato[nz][ny][nx]==-1) continue;
			if (tomato[nz][ny][nx]==0&&visit[nz][ny][nx]==0)
			{
				visit[nz][ny][nx] = visit[cz][cy][cx]+1;
				q.push(make_pair(nz, make_pair(ny, nx)));
			}

		}
	}
	for (int z = 0; z < H; z++)
	{
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				if (visit[z][y][x] == 0) check = false;
				time = max(time, visit[z][y][x]);
			}
		}
	}

	if(check) cout << time-1;
	else cout << -1;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Input();
	Solution();

	return 0;
}