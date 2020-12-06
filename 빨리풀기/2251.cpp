#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int a,b,c;
int visit[201][201][201];
typedef struct water
{
	int A;
	int B;
	int C;
};
queue<water>q;
vector<int> ans;
void Input()
{
	cin >> a >> b >> c;
}

void Solve()
{
	water curstate;
	curstate.A = 0;
	curstate.B = 0;
	curstate.C = c;
	q.push(curstate);
	
	while (!q.empty())
	{
		int cura = q.front().A;
		int curb = q.front().B;
		int curc = q.front().C;
		q.pop();

		if (visit[cura][curb][curc] == 1) continue;
		
		if (cura == 0)
		{
			ans.push_back(curc);
		}
		
		visit[cura][curb][curc] = 1;
		
		if (cura + curb > b)
		{
			q.push({ cura + curb - b,b,curc });
		}
		else
		{
			q.push({ 0,cura + curb,curc });
		}//a->b

		if (cura + curc > c)
		{
			q.push({ cura + curc - c,curb,c });
		}
		else
		{
			q.push({ 0,curb,cura + curc });
		}//a->c

		if (curb + cura > a)
		{
			q.push({ a,curb + cura - a,curc });
		}
		else
		{
			q.push({ curb + cura,0,curc });
		}//b->a

		if (curb + curc > c)
		{
			q.push({ cura,curb + curc - c,c });
		}
		else
		{
			q.push({ cura,0,curb + curc });
		}//b->c

		if (curc + cura > a)
		{
			q.push({ a,curb,curc + cura - a });
		}
		else
		{
			q.push({ curc + cura,curb,0 });
		}//c->a

		if (curc + curb > b)
		{
			q.push({ cura,b,curc + curb - b });
		}
		else
		{
			q.push({ cura,curc + curb,0 });
		}//c->b

	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i]<<" ";
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Input();
	Solve();

	return 0;
}