#include <cstdio>
#include <algorithm>
using namespace std;
int dp[1001][1001] = { 0, };
int map[1001][1001] = { 0, };
#pragma warning(disable:4996)

int max(int a, int b)
{
	return a > b ? a : b;
}


int main()
{
	int n;
	scanf("%d", &n);
	if(n%2==0) 	printf("CY");
	else printf("SK");
	

	return 0;
}