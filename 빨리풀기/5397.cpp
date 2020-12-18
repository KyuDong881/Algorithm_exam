#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int tc;


void Solve(string keylog);

void Input()
{
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		string keylog = "";
		cin >> keylog;
		Solve(keylog);

	}
}

void Solve(string keylog)
{
	int cursor = 0;
	string answer = "";
	deque<char> pw;
	queue<char> hack;
	deque<char> tmp;
	for (int i = 0; i < keylog.size(); i++)
		hack.push(keylog[i]);

	while (!hack.empty())
	{
		char cur = hack.front();
		hack.pop();
		
		if (cur == '<')
		{
			if (pw.empty()) continue;
			char word = pw.back();
			pw.pop_back();
			tmp.push_front(word);
		}

		else if (cur == '>')
		{
			if (tmp.empty()) continue;
			char word = tmp.front();
			tmp.pop_front();
			pw.push_back(word);
		}

		else if (cur == '-')
		{
			if (pw.empty()) continue;
			pw.pop_back();
		}

		else
			pw.push_back(cur);
	}

	while (!tmp.empty())
	{
		pw.push_back(tmp.front());
		tmp.pop_front();
	}

	while (!pw.empty())
	{
		answer.push_back(pw.front());
		pw.pop_front();
	}
	cout << answer << "\n";

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Input();

	return 0;
}