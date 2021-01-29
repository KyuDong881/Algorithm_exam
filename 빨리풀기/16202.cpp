#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, K;
vector<pair<int, pair<int, int>>> v;
vector<int> v2[1001];
int parent[1001];
void Input()
{
	cin >> N >> M >> K;
	int weight = 1;
	for (int i = 0; i < M; i++) {
		int st, dt;
		cin >> st >> dt;
		v.push_back(make_pair(weight, make_pair(st, dt)));

		weight++;
	}

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}


}

int find_parent(int x)
{
	if (parent[x]==x) return x;
	else return parent[x] = find_parent(parent[x]);

}

void Union(int x, int y)
{
	x = find_parent(x);
	y = find_parent(y);
	if (x != y) {
		parent[y] = x;
	}
}

bool check_cycle(int y, int x)
{
	if (find_parent(x) == find_parent(y)) {
		return true;
	}
	else return false;
}


void Solve()
{
	sort(v.begin(), v.end());
	int turn = 0;
	int score = 0;
	int cnt = 0;
	while (1) {
		score = 0;
		if (turn == K) break;
		cnt = 0;
			for (int i = 0; i <v.size(); i++) {
				int weight = v[i].first;
				int start = v[i].second.first;
				int dest = v[i].second.second;

				if (check_cycle(start, dest) == false) {
					Union(start, dest);
					score += weight;
					cnt++;
				}
			}
			if (cnt == N - 1) {
				cout << score << " ";
				v.erase(v.begin(), v.begin() + 1);
				for (int i = 1; i <= N; i++) {
					parent[i] = i;
				}
			}
			else cout << 0 << " ";

		turn++;
		
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