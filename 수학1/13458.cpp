#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int N, A, B, C;
vector<int> room;
long long answer = 0;
int directNum = 0;
long long people = 0;
void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		room.push_back(A);
	}
	cin >> B >> C;
}

void Solve()
{
	for (int i = 0; i < N; i++)
	{
		people = room[i];
		people = people - B;
		answer++;
		if (people > 0)
		{
			long long k = people / C;
			answer += k;
			if (people%C != 0) answer++;
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
	cout << answer;
}
