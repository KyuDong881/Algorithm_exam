#include <iostream>
#include <algorithm>
using namespace std;

#define A 3
#define B 5
int ans1, ans2;
int main()
{
	int a, b, v;
	cin >> a >> b >> v;
	ans1 = 0;
	if ((v - a) % (a - b) == 0)
		ans1 = (v - a) / (a - b);
	else
		ans1 = (v - a) / (a - b) + 1;

	ans1++;
	cout << ans1;
}