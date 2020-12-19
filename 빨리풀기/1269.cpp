#include <iostream>
#include <vector>
#include <set>
using namespace std;
int a, b;

set<int> A;
set<int> B;

void Input()
{
	cin >> a >> b;
	for (int i = 0; i < a; i++)
	{
		int k;
		cin >> k;
		A.insert(k);
	}

	for (int i = 0; i < b; i++)
	{
		int k;
		cin >> k;
		if (A.count(k)) A.erase(k);
		else A.insert(k);
	}

}

void Solve()
{
	cout << A.size();

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