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
	if (n == 1) cout << "A"; //다음 수 알 수없음 A
	if (n == 2)
	{
		if (arr[1] == arr[2]) cout << arr[1]; //1번 2번이 같으면 3번은 같은수
		else cout << "A"; //다르면 알수없음 변수 2개 식 1개
	}
	if (n >= 3)
	{
		if (arr[1] == arr[2])
		{
			for (int i = 1; i <= n; i++)
			{
				if (arr[i] != arr[1])
				{
					cout << "B"; //1,2수가 같으면 뒤의 수들도 같은지 판별해서 다른게 있으면 B
					return;
				}
			}
			cout << arr[1]; // 다 같으면 다음 수도 같은 수
		}
		else
		{
			if ((arr[2] - arr[3]) % (arr[1] - arr[2]) != 0) //기울기가 정수가 아닌경우
			{
				cout << "B";
				return;
			}
			int a, b;
			a = (arr[2] - arr[3]) / (arr[1] - arr[2]); //기울기
			b = arr[2] - arr[1] * a;//y절편
			
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