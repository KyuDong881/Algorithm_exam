#include <iostream>
#include <algorithm>
#define NOANS 10000 ;
using namespace std;
int n, m, h;
int target[11] = { 0,1,2,3,4,5,6,7,8,9,10 };

int ladder[31][11] = { 0, };
int answer = NOANS;

bool check()
{
	int tmp[11] = { 0,1,2,3,4,5,6,7,8,9,10 };
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (ladder[i][j] == 1)
			{
				int x = tmp[j];
				tmp[j] = tmp[j + 1];
				tmp[j + 1] = x;
			}
		}

	}

	
	for (int i = 1; i <= n; i++)
	{
	
		if (tmp[i] != i) return false;
	}

	return true;

}

void Input()
{
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		ladder[a][b] = 1;
	}
}

void Solve(int cnt,int garo)
{
	if (cnt > 3) return;
	if (check())
	{
		answer = min(answer,cnt);
		return;
	}

	for (int i = garo; i <= h; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (ladder[i][j] == 1) continue;
			if (ladder[i][j - 1] == 1) continue;
			if (ladder[i][j + 1] == 1) continue;

			ladder[i][j] = 1;
			Solve(cnt + 1, i);
			ladder[i][j] = 0;

		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Input();
	Solve(0, 1);
	
	if (answer == 10000)
	{
		cout << -1;
	}
	else cout << answer;


	return 0;
}