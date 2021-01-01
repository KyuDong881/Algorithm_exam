#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int V, E;
int K;
int u, v, w;
vector<pair<int,int>> info[20000];
priority_queue<pair<int, int>> pq;
int dist[20000] = { 9999999, };

void Input()
{
	cin >> V >> E >> K;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		info[u].push_back(make_pair(v, w));
	}
}

void Solve()
{
	pq.push(make_pair(K, 0));
	dist[K] = 0;

	while (!pq.empty())
	{
		int curnode = pq.top().first;
		int weight = pq.top().second;
		pq.pop();

		for (int i = 0; i < info[cur].size(); i++)
		{
			int nextnode = info[cur][i].first;
			int nextweight = info[cur][i].second;
			int tdist = weight + nextweight;
			if (dist[nextnode] > tdist)
			{
				dist[nextnode] = tdist;
				pq.push(make_pair(nextnode, tdist));
			}
		}
	}

	for (int i = 0; i <= V; i++)
	{
		if (dist[i] == 9999999) cout << "INF" << "\n";
		else cout << dist[i] << "\n";
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