#include <iostream>
#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
int arr1[100001];
int N, M;
int x;
int returnIndexBinary(int x,int len)
{
	int start = 0;
	int fininsh = len - 1;
	while (start <= fininsh)
	{
		int mid = (start + fininsh) / 2;
		if (arr1[mid] < x)
			start = mid + 1;
		else if (arr1[mid] > x)
			fininsh = mid - 1;
		else
			return mid;
	}
	return -1;
}

int main()
{
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++)
	{
		scanf("%1d", &arr1[i]);
		getchar();
	}
		
	sort(arr1, arr1 + N);

	scanf("%d", &M);
	getchar();
	while (M--)
	{
		scanf("%d", &x);
		getchar();
		int check = returnIndexBinary(x,N);
		if (check == -1)
			printf("0\n");
		else
			printf("1\n");
	}
}