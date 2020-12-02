#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int a,b;
queue<int> q;
int visit[501] = { 0, };
vector<int> friends[501];
int answer = 0;
void Input()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}

}

void Solve()
{
	int silchin = 0;
	int chinchin = 0;
	visit[1] = 1;
	for (int i = 0; i < friends[1].size(); i++)
	{
		silchin = friends[1][i];
		visit[silchin] = 1;
		q.push(silchin);
		answer++;
	}
	//실친 초대
	while (!q.empty())
	{
		silchin = q.front();
		q.pop();
		for (int i = 0; i < friends[silchin].size(); i++)
		{
			chinchin = friends[silchin][i];
			if (visit[chinchin] == 1) continue;
			visit[chinchin] = 1;
			answer++;
		}
	}
	//친구의 친구 초대

}

int main()
{
	Input();
	Solve();
	cout << answer;
	
	return 0;
}