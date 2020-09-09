#include <iostream>
#include <algorithm>
using namespace std;

#define A 3
#define B 5
int ans1, ans2;
int main()
{
	int n;
	cin >> n;

	int index = 1;
	while (1)
	{
		if (index*(index+1)/2 >= n) break;
		index++;
	}
	int dif;
	dif = (index * (index + 1) / 2) - n;
	if (index % 2 == 0)
	{
		ans1 = index - dif;
	}
	else
	{
		ans1 = 1 + dif;
	}
	ans2 = index - ans1 + 1;
		
	cout << ans1<<'/'<<ans2;
	
}