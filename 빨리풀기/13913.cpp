#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
int n, k;
int answer = 0;
bool visit[100001];
int from[100001];
int dx[3] = { 1,-1,2 };

stack<int> s;
/*
�����̴� ������ ���ٲ����� �ϰ� �ִ�. �����̴� ���� �� N(0 �� N �� 100,000)�� �ְ�, ������ �� K(0 �� K �� 100,000)�� �ִ�. 
�����̴� �Ȱų� �����̵��� �� �� �ִ�. 
����, �������� ��ġ�� X�� �� �ȴ´ٸ� 1�� �Ŀ� X-1 �Ǵ� X+1�� �̵��ϰ� �ȴ�. 
�����̵��� �ϴ� ��쿡�� 1�� �Ŀ� 2*X�� ��ġ�� �̵��ϰ� �ȴ�.
*/

void Input()
{
	cin >> n >> k;
}

void Solve()
{
	visit[n] = true;
	queue<pair<int,int>> q;
	q.push(make_pair(n,0));
	
	while (!q.empty())
	{
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cur == k)
		{
			answer = cnt;
			cout << cnt << "\n";
			return;
		}

		for (int i = 0; i < 3; i++)
		{
			if (i == 2)
			{
				int n_cur = cur * dx[i];
				if (n_cur < 0 || n_cur>100000) continue;
				if (visit[n_cur]) continue;
				visit[n_cur] = true;
				from[n_cur] = cur;
				q.push(make_pair(n_cur, cnt + 1));
			}

			else
			{
				int n_cur = cur + dx[i];
				if (n_cur < 0 || n_cur>100000) continue;
				if (visit[n_cur]) continue;
				visit[n_cur] = true;
				from[n_cur] = cur;
				q.push(make_pair(n_cur, cnt + 1));
			}

		}
	}
}

void From(int x,int cnt)
{
	if (cnt == answer)
	{
		while (!s.empty())
		{
			int tmp = s.top();
			s.pop();
			cout << tmp << " ";
		}
		return;
	}
	int prev = from[x];
	s.push(prev);
	From(prev, cnt + 1);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Input();
	if (n == k)
	{
		cout << 0 << "\n" << n;
	}
	else
	{
		Solve();
		s.push(k);
		From(k, 0);
	}
	return 0;
}

