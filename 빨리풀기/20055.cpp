#include <iostream>
#include <queue>
using namespace std;

int n, k, Start, End, Cnt, Answer;
int Belt[221];
bool Visit[221];
queue<int> Robot;

void Input()
{
	cin >> n >> k;
	for (int i = 1; i <= 2 * n; i++) cin >> Belt[i];

}

void Move_Belt()
{
	Start--;
	End--;
	if (Start < 1) Start = 2 * n;
	if (End < 1) End = 2 * n;
}

void Move_Robot()
{
	int Size = Robot.size();
	for (int i = 0; i < Size; i++)
	{
		int Cur = Robot.front();
		Visit[Cur] = false;
		Robot.pop();

		if (Cur == End) continue;

		int next = Cur + 1;
		if (next > 2 * n) next = 1;
		if (Belt[next] >= 1 && Visit[next] == false)
		{
			Belt[next]--;
			if (Belt[next] == 0) Cnt++;
			if (next == End) continue;
			Visit[next] = true;
			Robot.push(next);

		}
		else
		{
			Visit[Cur] = true;
			Robot.push(Cur);
		}
	}
}

void Make_Robot()
{
	if (Visit[Start] == false && Belt[Start] >= 1)
	{
		Visit[Start] = true;
		Belt[Start]--;
		Robot.push(Start);

		if (Belt[Start] == 0) Cnt++;
	}
}

void Solution()
{
	Start = 1;
	End = n;

	while (Cnt < k)
	{
		Answer++;

		Move_Belt();
		Move_Robot();
		Make_Robot();
	}
	cout << Answer << endl;
}

void Solve()
{
	Input();
	Solution();
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nULL);
	cout.tie(nULL);

	Solve();

	return 0;
}