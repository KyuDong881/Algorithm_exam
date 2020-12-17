#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> nol;
vector<string> nos;
int n, m;
int ans = 0;

int board[301][301] = { 0, };
int visit[301][301] = { 0, };
int temp[301][301] = { 0, };
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };

vector<string> answer;

void Input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		nol.push_back(s);
	}

	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		nos.push_back(s);
	}

}

bool bs(int low, int high,string target)
{
	if (low > high)
		return false;

	else
	{
		int mid = (low + high) / 2;

		if (!nol[mid].compare(target))
			return true;
		else if (nol[mid] > target)
			return bs(low, mid - 1, target);
		else
			return bs(mid + 1, high, target);
	}
}

void Solve()
{
	sort(nol.begin(), nol.end());
	for (int i = 0; i < nos.size(); i++)
	{
		if (bs(0, nol.size() - 1, nos[i]))
		{
			answer.push_back(nos[i]);
			ans++;
		}
	}

	sort(answer.begin(), answer.end());

	cout << ans << "\n";
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
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