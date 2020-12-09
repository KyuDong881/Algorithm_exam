#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, s;
int arr[21];
int answer = 0;
void Input()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void dfs(int i, int sum) {
	if (i == n) return;
	if (sum + arr[i] == s) answer++;

	dfs(i + 1, sum);
	dfs(i + 1, sum + arr[i]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Input();
	dfs(0, 0);
	cout << answer;
}