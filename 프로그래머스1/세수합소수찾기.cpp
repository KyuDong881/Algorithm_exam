#include <vector>
#include <iostream>
using namespace std;

bool prime(int result)
{
	for (int i = 2; i <= result / 2; i++)
	{
		if (result%i == 0) return false;
	}
	return true;
}

int solution(vector<int> nums) {
	int answer = -1;
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			for (int k = j + 1; k < nums.size(); k++)
			{
				int result = nums[i] + nums[j] + nums[k];
				cout << result;
				if (prime(result)) answer++;
			}
		}
	}
	// [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.

	return answer;
}
int main()
{
	vector<int> v = { 1,2,3,4 };
	int ans;
	ans = solution(v);
	printf("%d", ans);
}