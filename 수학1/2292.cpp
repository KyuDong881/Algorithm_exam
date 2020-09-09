#include <iostream>
#include <algorithm>
using namespace std;

#define A 3
#define B 5

int main()
{
	int n;
	cin >> n;

	int room = 0;
	while (1)
	{
		if ((3 * room*(room + 1) + 1) >= n) break;
		room++;
	}

	cout << room+1;
	
}