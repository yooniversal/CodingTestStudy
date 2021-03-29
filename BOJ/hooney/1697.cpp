#include<iostream>
#include<math.h>
using namespace std;
int arr[300001];
int main()
{
	int N, K,i;
	cin >> N >> K;
	for (i = 0;i <= K;i++)
	{
		arr[i] = 9999;
	}
	for (i = N;i >= 0;i--)
	{
		arr[i] = N - i;
	}
	for (i = N+1;i <= K+2;i++)
	{
		if (i % 2 == 0)
		{
			arr[i] = min(arr[i - 1], arr[i / 2]) + 1;
		}
		else
		{
			arr[i] = min(arr[i - 1], min(arr[(i + 1) / 2] + 1, arr[(i - 1) / 2] + 1)) + 1;
		}
	}
	//for (i = 0;i <= K+2;i++)
	//{
	//	cout << i << ": " << arr[i] << endl;
	//}
	cout << arr[K];
}