#include <stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#define MAX 10000000
int arr[1000000];
using namespace std;
int cnt;
int ret=1000000;
int mini(int n)
{
	for (int i = 2; i <= n; i++)
	{
		arr[i] = arr[i - 1] + 1;
		if (arr[i] % 3 == 0)arr[i] = min(arr[i], arr[i / 3] + 1);
		if (arr[i] % 2 == 0)arr[i] = min(arr[i], arr[i / 2] + 1);

		
	}
	return arr[n];
}
int main(void)
{
	int x;
	cin >> x;
	for (int i = 1; i <= x; i++)
	{
		arr[i] = -1;
	}
	arr[1] = 0;
	cout << mini(x);
}