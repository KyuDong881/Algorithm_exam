#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1000000007

using namespace std;
int TC, N, M, W;
int dist[511];

bool Solve(vector<pair<int, pair<int, int>>> v);
void Input()
{
	cin >> TC;
	for (int i=0; i < TC; i++)
	{

		for (int j = 1; j < 511; j++)
			dist[j] = INF;

		bool flag = false;
		vector<pair<int,pair<int, int>>> v;
		v.clear();
		cin >> N >> M >> W;
		for (int j = 0; j < M;j++)
		{
			int S, E, T;
			cin >> S >> E >> T;
			v.push_back(make_pair(T, make_pair(S, E)));
			v.push_back(make_pair(T, make_pair(E, S)));
		}
		for (int j = 0; j < W; j++)
		{
			int S, E, T;
			cin >> S >> E >> T;
			v.push_back(make_pair(-T, make_pair(S, E)));
		}

		if(Solve(v)) flag=true;
		if (flag) cout << "YES"<< "\n";
		else cout << "NO"<< "\n";

	}//tc for end
}

bool Solve(vector<pair<int,pair<int, int>>> v)
{
	dist[1] = 0;
	for (int i = 0; i < N-1; i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			int weight = v[j].first;
			int start = v[j].second.first;
			int dest = v[j].second.second;

			if (dist[dest] > dist[start] + weight) dist[dest] = dist[start] + weight; 
		}
	}

	for (int j = 0; j < v.size(); j++)
	{
		int weight = v[j].first;
		int start = v[j].second.first;
		int dest = v[j].second.second;

		if (dist[dest] > dist[start] + weight)
		{
			return true;
		}
	}

	return false;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Input();
	
	return 0;
}