/*
�Է��� ���� ���� �׽�Ʈ ���̽��� �̷���� �ִ�. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ִ�. ù ��° ���� k (6 < k < 13)�̰�, 
���� k�� ���� ���� S�� ���ԵǴ� ���̴�. 
S�� ���Ҵ� ������������ �־�����.
�Է��� ������ �ٿ��� 0�� �ϳ� �־�����.
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