#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
#include <deque>
#include <vector>
using namespace std;


int n, m;
int ans = 0;

int board[301][301] = { 0, };
int visit[301][301] = { 0, };
int temp[301][301] = { 0, };
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };

deque<int> dq;

void Solve(string s, deque<int> dq);

void Input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		deque<int> dq;
		string s;
		cin >> s;
		cin >> m;
		string arr;
		string tmp = "";
		cin >> arr;
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i] == '[' || arr[i] == ']' || arr[i] == ',') continue;
			else
			{
				tmp = tmp + arr[i];
				if (arr[i + 1] == ',' || arr[i + 1] == ']')
				{

					int value = stoi(tmp);
					dq.push_back(value);
					tmp = "";
				}
			}
		}
		Solve(s, dq);

	}


}

void Solve(string s, deque<int> dq)
{
	int dir = 1;
	int flag = -1;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'R')
		{
			dir = dir * flag;
		}

		else
		{
			if (dir == 1)
			{
				if (dq.empty())
				{
					cout << "error" << "\n";
					return;
				}
				dq.pop_front();
			}
			else
			{
				if (dq.empty())
				{
					cout << "error" << "\n";
					return;
				}
				dq.pop_back();
			}

		}
	}
	cout << '[';
	while (!dq.empty())
	{
		if (dir == 1)
		{
			int value = dq.front();
			dq.pop_front();
			if (dq.size() == 0)
				cout << value;
			else
				cout << value << ',';
		}
		else
		{
			int value = dq.back();
			dq.pop_back();
			if (dq.size() == 0)
				cout << value;
			else
				cout << value << ',';
		}
	}

	cout << ']' << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Input();

	return 0;

}