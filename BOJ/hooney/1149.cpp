#include<iostream>
#include<math.h>
#include <vector>
#include <stack>
#include <map>
#include<math.h>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int arr[1001][3];
	//memset(arr, 0, sizeof(arr));
	int r, g, b;
	for (int i = 0; i < N; i++)
	{
		cin >> r >> g >> b;

		arr[i][0] = r;
		arr[i][1] = g;
		arr[i][2] = b;
	}

	for (int i = 1; i < N; i++)
	{
		arr[i][0] = arr[i][0] + min(arr[i - 1][1], arr[i - 1][2]);
		arr[i][1] = arr[i][1] + min(arr[i - 1][0], arr[i - 1][2]);
		arr[i][2] = arr[i][2] + min(arr[i - 1][1], arr[i - 1][0]);
	}
	int t = min(arr[N - 1][1], arr[N - 1][2]);
	cout << min(arr[N - 1][0],t);
}