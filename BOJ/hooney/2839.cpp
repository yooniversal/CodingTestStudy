#include<iostream>
using namespace std;
int main()
{
	int arr[6000];
	int n;
	cin >> n;
	if (n == 1 || n == 2 || n == 7 || n == 4) { cout << -1; return 0; }
	if (n == 3 || n == 5){cout << 1; return 0;
}
	if (n == 6) { cout << 2; return 0; }
	arr[1] = 9999; arr[2] = 9999; arr[4] = 9999; arr[7] = 9999;
	arr[3] = 1; arr[5] = 1;
	arr[6] = 2;
	for (int i = 7; i <= n; i++)
	{
		if (arr[i - 3] < arr[i - 5])arr[i] = arr[i - 3] + 1;
		else arr[i] = arr[i - 5] + 1;
	}
	cout << arr[n];
}