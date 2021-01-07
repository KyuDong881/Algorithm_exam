#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int ans = 1000000;
int n;
vector<int> v[11];
int human[11];
bool choice[11];
int flag = -1;

void Input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> human[i];
	
	for (int i = 1; i <= n; i++)
	{
		int linknum;
		cin >> linknum;
		for (int j = 0; j < linknum; j++)
		{
			int linknode;
			cin >> linknode;
			v[i].push_back(linknode);
		}
	}
}

bool check_area()
{
	bool visit[11];
	for (int i = 1; i <= n; i++)
		visit[i] = false;

	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (choice[i])
		{
			q.push(i);
			visit[i] = true;
			break;
		}
			
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++)
		{
			int nx = v[cur][i];
			if (choice[nx] == false) continue;
			if (visit[nx] == true) continue;
			visit[nx] = true;
			q.push(nx);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (choice[i] != visit[i])
		{
			return false;
		}
	}

	return true;
}

void dfs(int sel,int cnt, int idx)
{
	if (cnt == sel)
	{
		if (check_area())
		{
			flag = 1;
			int answer = 0;
			for (int i = 1; i <= n; i++)
			{
				if (choice[i])
				{
					answer = answer + human[i];
				}
				else
					answer = answer - human[i];
			}

			answer = abs(answer);
			ans = min(answer, ans);
			return;
		}
		else return;
	}

	for (int i = idx; i <= n; i++)
	{
		if (choice[i] == true) continue;
		choice[i] = true;
		dfs(sel, cnt + 1, i);
		choice[i] = false;
	}

}


void Solve()
{
	for (int i = 1; i <= n; i++)
	{
		dfs(i,0,1);
	}
	if (flag == -1) cout << -1;
	else
		cout << ans;
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