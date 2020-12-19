#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> arr;

void Input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int value;
		cin >> value;
		arr.push_back(value);
	}
}

void Solve()
{
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i];
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