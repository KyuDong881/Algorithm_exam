#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<vector<int>> board;
int board1[101][101];
int ans = 0;

void copyvector(vector<vector<int>> board)
{
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			board1[i][j] = board[i][j];
		}
	}
}

void solution(vector<vector<int>> board)
{
	const int dx[4] = { 0,1,0,-1 };
	const int dy[4] = { 1,0,-1,0 };
	copyvector(board);
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board1[i][j] == 1)
				board1[i][j] = 4;
		}
	}

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board1[i][j] == 4)
			{
				for (int dir = 0; dir < 4; dir++)
				{
					int nx = j + dx[dir];
					int ny = i + dy[dir];
					if (nx < 0 || ny < 0 || ny >= board.size() || nx >= board[i].size()) continue;
					if (board1[ny][nx] == 0) continue;
					else board1[i][j]--;
				}
			}
		}
	}
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			ans += board1[i][j];
		}
	}
	
}


int main()
{
	board = { {1,0,1,1},{0,0,1,1},{1,1,0,1},{1,1,0,0} };
	solution(board);

	printf("%d", ans);
}