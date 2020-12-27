#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<int>q;

int main()
{
	string s;
	int cnt;
	cin >> cnt;
	while (1)
	{
		if (cnt == 0) break;
		cnt--;
		cin >> s;
		if (!s.compare("push"))
		{
			int x;
			cin >> x;
			q.push(x);
		}
		if (!s.compare("front"))
		{
			if (!q.empty())
			{
				int a = q.front();
				cout << a << "\n";
			}
			else cout << -1 << "\n";
		}
		if (!s.compare("pop"))
		{
			if (!q.empty())
			{
				int a = q.front();
				q.pop();
				cout << a << "\n";
			}
			else cout << -1 << "\n";
		}

		if (!s.compare("size"))
		{
			cout << q.size() << "\n";
		}

		if (!s.compare("empty"))
		{
			if (!q.empty())
			{
				cout << 0 << "\n";
			}
			else cout << 1 << "\n";
		}
		if (!s.compare("back"))
		{
			if (!q.empty())
			{
				int a = q.back();
				cout << a << "\n";
			}
			else cout << -1 << "\n";
		}
	}
	return 0;
}