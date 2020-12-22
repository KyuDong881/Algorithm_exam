/*
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있다. 첫 번째 수는 k (6 < k < 13)이고, 
다음 k개 수는 집합 S에 포함되는 수이다. 
S의 원소는 오름차순으로 주어진다.
입력의 마지막 줄에는 0이 하나 주어진다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int k;
int arr[13];
bool check[13];


void Print()
{
	for (int i = 0; i < k; i++)
	{
		if (check[i]) cout << arr[i] << " ";
	}
	cout << "\n";
}

void Solve(int cnt,int idx)
{
	if (cnt == 6)
	{
		Print();
		return;
	}

	for (int i = idx; i < k; i++)
	{
		if (check[i]) continue;
		check[i] = true; 
		Solve(cnt + 1,i);
		check[i] = false;
	}

}

void Input()
{
	while (1)
	{
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++)
		{
			int a;
			cin >> a;
			arr[i] = a;
		}
		Solve(0,0);
		cout << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Input();

	return 0;
}