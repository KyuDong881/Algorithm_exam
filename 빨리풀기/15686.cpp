#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
int board[51][51] = { 0, };
bool check[13];
int answer = 9999;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;

void Input()
{
	int tmp;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> tmp;
			board[i][j] = tmp;
			if (tmp == 1) home.push_back(make_pair(i, j)); //집 위치 벡터
			if (tmp == 2) chicken.push_back(make_pair(i, j)); //치킨집 위치 벡터
		}
	}
}
void Cal()
{
	int tmp_ans = 0;
	for (int i = 0; i < home.size(); i++)
	{
		int dist = 9999;
		for (int j = 0; j < chicken.size(); j++)
		{
			if (check[j])
			{
				int tmp = 0;
				tmp = abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second);
				dist = min(dist, tmp);
			}
		}
		tmp_ans += dist;
	}
	answer = min(answer, tmp_ans);
}


void check_chic(int choice,int idx)
{
	if (choice == m)
	{
		Cal();
		return;
	}
	//m개 뽑고 계산 return

	for (int i = idx; i < chicken.size(); i++)
	{
		if (check[i]) continue;
		check[i] = true;
		check_chic(choice + 1, i);
		check[i] = false;
	}
}

void Solve()
{
	check_chic(0, 0);
	cout << answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Input();
	Solve();

}