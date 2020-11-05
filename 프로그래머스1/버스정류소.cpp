#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int vis[601][601] = { 0, };
vector<vector<int>> ans(600, vector<int>(600, -1));
queue<vector<int>>q;

void bfs(int n,vector<int> bus)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			vis[i][j] = 0;

	bus[0] -= 1;
	bus[1] -= 1;
	ans[bus[0]][bus[1]] = 0;
	vis[bus[0]][bus[1]] = 1;
	q.push(bus);
	while (!q.empty())
	{
		vector<int> cur = q.front();
		int yy = cur[0];
		int xx = cur[1];

		q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = xx + dx[dir];
			int ny = yy + dy[dir];
			
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (vis[ny][nx] == 1) continue;
			
			vis[ny][nx] = 1;
			if (ans[ny][nx] == -1)
			{
				ans[ny][nx] = ans[yy][xx] + 1;
			}
			else
			{
				ans[ny][nx] = min(ans[yy][xx] + 1,ans[ny][nx]);
			}
			vector<int> nq = { ny,nx };
			q.push(nq);
			
		}
		
	}

}


vector<vector<int>> solution(int n,vector<vector<int>> maps) {
	
	vector<vector<int>> answer;
	int mapsize = maps.size();
	for (int i = 0; i < mapsize; i++)
	{
		vector<int> curnode = maps[i];
		bfs(n,curnode);
	}

	return answer;

}

int main()
{
	int n = 3;
	vector<vector<int>> maps = { {1,2},{2,3} };
	solution(n, maps);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	//printf("%d", maps.size());
	return 0;
}