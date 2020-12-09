#include <vector>
#include <iostream>
#include <string>
using namespace std;
vector<string> v = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
vector<int>month = { 0,30,28,31,30,31,30,31,31,30,31,30,31 };
int m, d;
string solution(int a, int b) {

	string answer = "";
	int date = 0;
	for (int i = 0; i < a; i++)
		date += month[i];
	if (a == 1) date += (b - 1);
	else date += b;
	answer = v[(date % 7)];
	return answer;
}

void Input()
{
	cin >> m >> d;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Input();
	string ans;
	ans = solution(m, d);
	cout << ans;
}