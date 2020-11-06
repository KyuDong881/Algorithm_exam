#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<int> tmp;
vector<int> solution(vector<string> operations) {

	int num;
	while (!operations.empty())
	{
		string oper = operations.front();
		if (oper[0] == 'I')
		{
			if (oper[2] == '-')
			{
				oper.erase(0, 3);
				num = stoi(oper);
				tmp.push_back(-num);
			}
			else
			{
				oper.erase(0, 2);
				num = stoi(oper);
				tmp.push_back(num);
			}
			sort(tmp.begin(), tmp.end(), greater<int>());
		}
		else if (oper[0] == 'D')
		{
			if (tmp.size() == 0)
			{
				operations.erase(operations.begin());
				continue;
			}
			if (oper[2] == '-')
			{
				tmp.pop_back();
			}
			else
			{
				tmp.erase(tmp.begin(), tmp.begin() + 1);
			}
		}
		operations.erase(operations.begin());
	}
	if (tmp.size() == 0)
	{
		vector<int>answer = { 0,0 };
		return answer;
	}
	else
	{
		int maxvalue = tmp[0];
		int minvalue = tmp[tmp.size()-1];
		vector<int> answer = { maxvalue,minvalue};
		return answer;
	}
}

int main()
{
	vector<string> v = { "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" };
	solution(v);
	return 0;
}