#include <iostream>
#include <cstring>
using namespace std;

int check[26];
char A[102];
int N, com;;
long long dab;

void dfs(int d, int sum)
{
	if (d == N - 1)
	{
		if (sum == com) dab++;
		return;
	}
	if (d + 1 < N)
	{
		dfs(d + 1, sum | check[d + 1]);
		dfs(d + 1, sum);
	}
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < 26; i++) com |= 1 << i;

	for (int i = 0; i < N; i++)
	{
		cin >> A;
		for (int j = 0; j < strlen(A); j++)
			check[i] |= (1 << (A[j] - 'a'));
	}
	dfs(-1, 0);
	cout << dab << endl;
}