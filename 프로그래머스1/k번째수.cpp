#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> commands) {
	int tmp = commands.size();
	int idx = 0;
	vector<int> answer;
	for (int i = 0; i < commands.size(); i++)
	{
		vector<int>temp;
		for (int j = commands[i][0] - 1; j < commands[i][1]; j++)
		{
			temp.push_back(arr[j]);
		}
		sort(temp.begin(), temp.end());
		answer.push_back(temp[commands[i][2] - 1]);
	}
	return answer;
}


int main()
{
	vector<int> arr = { 1, 5, 2, 6, 3, 7, 4 };
	vector<vector<int>> commands = { {2, 5, 3},{4, 4, 1},{1, 7, 3} };
	vector<int>answer;
	answer = solution(arr, commands);
	printf("%d %d %d", answer[0], answer[1], answer[2]);
}

//[1, 5, 2, 6, 3, 7, 4]	[[2, 5, 3], [4, 4, 1], [1, 7, 3]]   [5, 6, 3]