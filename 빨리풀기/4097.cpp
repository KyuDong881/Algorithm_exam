#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n,m,a,b;
int visit[100002] = { 0, };
queue<pair<int,int>> q;

int answer = 0;
int dir[8];

void Input()
{
	cin >> a >> b >> n >> m;
	dir[0] = 1;
	dir[1] = -1;
	dir[2] = a;
	dir[3] = -a;
	dir[4] = b;
	dir[5] = -b;
	dir[6] = a;
	dir[7] = b;
}

void Solve()
{
	visit[n] = 1;
	q.push(make_pair(n,0));
	while (!q.empty())
	{

		int cur = q.front().first;
		int count = q.front().second;
		q.pop();
		if (cur == m)
		{
			cout << count;
			return;
		}

		for (int i = 0; i < 8; i++)
		{
			int next;

			if (i > 5) next = cur * dir[i];

			else {
				next = cur + dir[i];
			}

			if (next < 1 || next>100000) continue;
			if (visit[next] == 1) continue;

			visit[next] = 1;
			q.push(make_pair(next, count+1));
		}
		
	}
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