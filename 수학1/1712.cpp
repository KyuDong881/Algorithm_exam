#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a, b, c;
	int ans;
	
	cin >> a >> b >> c;

	if (c > b)
		ans = a / (c - b) + 1;
	else ans = -1;

	cout << ans;
	
}