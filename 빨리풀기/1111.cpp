#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n;
int arr[51];

void Input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

void Solve()
{
	if (n == 1) cout << "A"; //���� �� �� ������ A
	if (n == 2)
	{
		if (arr[1] == arr[2]) cout << arr[1]; //1�� 2���� ������ 3���� ������
		else cout << "A"; //�ٸ��� �˼����� ���� 2�� �� 1��
	}
	if (n >= 3)
	{
		if (arr[1] == arr[2])
		{
			for (int i = 1; i <= n; i++)
			{
				if (arr[i] != arr[1])
				{
					cout << "B"; //1,2���� ������ ���� ���鵵 ������ �Ǻ��ؼ� �ٸ��� ������ B
					return;
				}
			}
			cout << arr[1]; // �� ������ ���� ���� ���� ��
		}
		else
		{
			if ((arr[2] - arr[3]) % (arr[1] - arr[2]) != 0) //���Ⱑ ������ �ƴѰ��
			{
				cout << "B";
				return;
			}
			int a, b;
			a = (arr[2] - arr[3]) / (arr[1] - arr[2]); //����
			b = arr[2] - arr[1] * a;//y����
			
			for (int i = 1; i < n; i++)
			{
				if (arr[i] * a + b != arr[i + 1])
				{
					cout << "B";
					return;
				}
			}
			cout << arr[n] * a + b;
		}
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