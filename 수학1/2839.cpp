#include <iostream>
#include <algorithm>
using namespace std;

#define A 3
#define B 5

int main()
{
	int n;
	cin >> n;
	int three, five = 0;
	
	five = n / 5;
	int tmp;
	tmp = n % 5;

	int ans;

	while (1)
	{
		if (tmp % 3 == 0)
		{
			three = tmp / 3;
			break;
		}
		
		tmp += 5;
		five--;
		if (five < 0) break;
	}
	if (five < 0) ans = -1;
	else	ans = five + three;

	cout << ans;
	
}