#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int v[100010]; //이분탐색으로 가능할듯
long long answer = 0;
void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	sort(v, v + N);
}

int binary_search(int start, int left, int right)
{
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (v[mid] * 0.9 <= v[start])
			left = mid + 1;
		else
			right = mid;
	}
	return right-1;

}
//1 2 (10000000)
//0 1 2
void Solve()
{
	v[N] = 100000001;
	for (int i = 0; i < N-1; i++)//i번
	{
		int tmp = binary_search(i, i, N) - i;//1~n번까지 m개 2~n번까지 
		answer += tmp;
	}
	cout << answer;
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