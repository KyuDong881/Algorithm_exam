#include <iostream>
#include <queue>
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
int start = 1;

void bfs(int x)
{
	visit[x] = 1;
	q2.push(x);
	
	while (!q2.empty())
	{
		int xx = q2.front();
		q2.pop();
		for (int i = 1; i <= number; i++)
		{
			if (!visit[i] && board[xx][i]==1)
			{
				visit[i] = 1;
				q2.push(i);
				ans++;
			}
		}
	}
}

int main()
{
	cin >> number;
	cin >> link;
	for (int i = 0; i < link; i++)
	{
		cin >> com1 >> com2;
		board[com1][com2] = 1;
		board[com2][com1] = 1;
	}

	bfs(start);

	cout << ans;


}
