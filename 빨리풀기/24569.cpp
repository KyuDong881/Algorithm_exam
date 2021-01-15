#include <iostream>
#include <vector>
using namespace std;
int N,M;
unsigned long long subject[1001];
unsigned long long student[10001];
void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int k;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			int t;
			cin >> t;
			subject[i] |= ((long long)1 << t);
			//subject = subject || 1<<t ->의미는 서브젝트에 t자리를 1로 바꾸어라인데 사실은 t번째만 1인 수랑 오어연산을해라
		}
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int p;
		cin >> p;
		for (int j = 0; j < p; j++)
		{
			int q;
			cin >> q;
			student[i] |= ((long long)1 << q);
		}
	}

}

void Solve()
{

	for (int i = 0; i < M; i++)
	{
		int cnt = 0;
		unsigned long long tmp = ~student[i];
		for (int j = 0; j < N; j++)
		{
			if ((tmp&subject[j])==0) cnt++;
		}
		cout << cnt << "\n";
	}


}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Input();
	Solve();

	return 0;
}