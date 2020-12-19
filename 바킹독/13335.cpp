#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int n, w, l;
queue<pair<int, int>> q1;
queue<pair<int, int>> q2;
int anstime = 0;
void Input()
{
	cin >> n >> w >> l;

	for (int i = 0; i < n; i++)
	{
		int value;
		cin >> value;
		q1.push(make_pair(value, 0)); //대기 트럭
	}
}

void Solve()
{
	int curweight = 0;
	while (1)
	{
		if (q1.size()==0 && q2.size()==0) break;

		if (!q2.empty())
		{
			int q2size = q2.size();
			for (int i = 0; i < q2size; i++)
			{
				int a = q2.front().first;
				int b = q2.front().second;
				if (b == w)
				{
					q2.pop();
					curweight -= a;
				}
				else
				{
					q2.pop();
					q2.push(make_pair(a, ++b));
				}

			}
		}

		if (!q1.empty())
		{
			int car = q1.front().first;
			int time = q1.front().second;

			if (curweight + car > l)
			{
				anstime++;
				continue;
			}

			else
			{
				q1.pop();
				curweight += car;
				q2.push(make_pair(car, ++time));
				anstime++;
			}
		}
		else
			anstime++;
	
	}
	cout << anstime;
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