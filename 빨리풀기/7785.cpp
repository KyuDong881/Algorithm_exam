#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
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
set<string,greater<string>> companyLog;

void Input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string name, input;
		cin >> name >> input;
		if (!input.compare("enter"))
			companyLog.insert(name);
		else
			companyLog.erase(name);
	}


}

void Solve()
{
	set<string>::iterator it;
	for (it = companyLog.begin(); it != companyLog.end(); it++)
	{
		cout << *it << "\n";
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