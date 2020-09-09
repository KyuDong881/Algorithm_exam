#include <iostream>
#include <algorithm>
using namespace std;

#define A 3
#define B 5
int ans1, ans2;
int main()
{
	int h, w, n;
	int t;
	cin >> t;
	while (1)
	{
		cin >> h >> w >> n;

		int  floor = 1;
		while (1)
		{
			if (n <= floor*h) break;
			floor++;
		}
		ans1 = n - (floor - 1)*h;
		ans2 = floor;
		cout << ans1 * 100 + ans2;
		t--;
		if (t == 0) break;
		cout << '\n';
	}

}