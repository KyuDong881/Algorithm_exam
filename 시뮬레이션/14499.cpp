#include <iostream>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

int n, m, r, c, k;
int dir;
int board[21][21];

int dx[5] = { 0,1,-1,0,0 };
int dy[5] = { 0,0,0,-1,1 };
int dice[7];

void movedice(int nx,int ny,int dir)
{
	int temp[7];
	for (int i = 1; i < 7; i++)
		temp[i] = dice[i];
	if (dir == 1)
	{
		dice[1] = temp[4];
		dice[3] = temp[1];
		dice[4] = temp[6];
		dice[6] = temp[3];
	}
	if (dir == 2)
	{
		dice[1] = temp[3];
		dice[3] = temp[6];
		dice[4] = temp[1];
		dice[6] = temp[4];
	}
	if (dir == 3)
	{
		dice[1] = temp[5];
		dice[2] = temp[1];
		dice[5] = temp[6];
		dice[6] = temp[2];
	}
	if (dir == 4)
	{
		dice[1] = temp[2];
		dice[2] = temp[6];
		dice[5] = temp[1];
		dice[6] = temp[5];
	}
	
	if (board[ny][nx] == 0) board[ny][nx] = dice[6];
	else
	{
		dice[6] = board[ny][nx];
		board[ny][nx] = 0;
	}

	cout << dice[1] << endl;
}

int main()
{
	cin >> n >> m >> r >> c >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	}
	for (int i = 0; i < k; i++)
	{
		cin >> dir;
		int nx = c + dx[dir];
		int ny = r + dy[dir];

		if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

		movedice(nx,ny,dir);
		c = nx;
		r = ny;
	}

	return 0;

}