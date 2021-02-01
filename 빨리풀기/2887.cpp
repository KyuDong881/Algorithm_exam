#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, K;

typedef struct Planet {
	int x, y, z,num;
};

int answer = 0;
vector<Planet> vx, vy, vz;
vector<pair<int, pair<int, int>>> info;

int parent[100010];

bool compx(Planet a, Planet b) {
	return a.x < b.x;
}

bool compy(Planet a, Planet b) {
	return a.y < b.y;
}

bool compz(Planet a, Planet b) {
	return a.z < b.z;
}

bool cmpdist(pair<int, pair<int, int>> a,pair<int, pair<int, int>> b) {
	return a.first < b.first;
}

void Input()
{
	cin >> N;


	for (int i = 0; i < N; i++) {
		Planet p;
		cin >> p.x >> p.y >> p.z;
		p.num = i;
		vx.push_back(p);
		vy.push_back(p);
		vz.push_back(p);
	}
	
	sort(vx.begin(), vx.end(), compx);
	sort(vy.begin(), vy.end(), compy);
	sort(vz.begin(), vz.end(), compz);

	
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}
	
}
void make_edge()
{
	for (int i = 0; i < vx.size()-1; i++) {
		int dist = vx[i+1].x - vx[i].x;
		int start = vx[i].num;
		int dest = vx[i+1].num;
		info.push_back(make_pair(dist, make_pair(start, dest)));
	}

	for (int i = 0; i < vy.size() - 1; i++) {
		int dist = vy[i+1].y - vy[i].y;
		int start = vy[i].num;
		int dest = vy[i + 1].num;
		info.push_back(make_pair(dist, make_pair(start, dest)));
	}

	for (int i = 0; i < vz.size() - 1; i++) {
		int dist = vz[i+1].z - vz[i].z;
		int start = vz[i].num;
		int dest = vz[i + 1].num;
		info.push_back(make_pair(dist, make_pair(start, dest)));
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
	sort(info.begin(), info.end(),cmpdist);

	for (int i = 0; i < info.size(); i++) {
		int dist = info[i].first;
		int start = info[i].second.first;
		int dest = info[i].second.second;

		if (!check_cycle(start, dest)) {
			Union(start, dest);
			answer+=dist;
		}
	}
	cout << answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Input();
	make_edge();
	Solve();

	return 0;
}