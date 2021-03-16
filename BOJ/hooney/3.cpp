#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
struct block
{
	int size;
	unsigned long long used, number;
	block(int size, int number) :size(size), number(number), used(0) {}
};
vector<block> arr;
vector<block> blocks_need;
vector<block> blocks_x;
vector<block> blocks_y;

int solution(int n, int m, int k)
{
	//cout << "---------------" << endl;
	if (k == 0)return 1;
	int min_length = min(min(n, m), k);
	int i;
	for (i = int(arr.size()) - 1; i >= 0; i--)
	{
		if (arr[i].size <= min_length)break;
	}
	int i_temp = i;
	int n_temp = n;
	int m_temp = m;

	for (int j = 0; j < arr.size(); j++)
	{
		blocks_x[j].number = 0;
		blocks_y[j].number = 0;
	}
	while (n != 0)
	{
		if (n >= arr[i].size) { n -= arr[i].size; blocks_x[i].number++; }
		else i--;
		if (i == -1)return -1;
	}

	i = i_temp;
	while (m != 0)
	{
		if (m >= arr[i].size) { m -= arr[i].size; blocks_y[i].number++; }
		else i--;
		if (i == -1)return -1;
	}

	//for (int i = 0; i <= i_temp; i++)
	//{
	//	cout << "block_x: " << i << " 번째 size: " << blocks_x.size << ", number: " << blocks_x[i].number << endl;
	//}
	//for (int i = 0; i <= i_temp; i++)
	//{
	//	cout << "block_y: " << i << " 번째 size: " << blocks_y.size << ", number: " << blocks_y[i].number << endl;
	//}



	for (int j = 0; j <= i_temp; j++)
	{
		int x = m_temp / blocks_x[j].size * blocks_x[j].number;
		int y = n_temp / blocks_y[j].size * blocks_y[j].number;
		blocks_need[j].number = x + y - blocks_x[j].number * blocks_y[j].number;
		//cout << "x: " << x << ",y: " << y << ", blocks_need[j].number:" << blocks_need[j].number << endl;

	}
	int h = k / arr[i_temp].size;
	h *= arr[i_temp].size;
	for (int j = 0; j <= i_temp; j++)
	{
		arr[j].used += blocks_need[j].number * (h / blocks_need[j].size);
	}
	//return 1;
	solution(n_temp, m_temp, k - h);
}
int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		arr.clear();
		blocks_need.clear();
		blocks_x.clear();
		blocks_y.clear();
		for (int j = 0; j < N; j++)
		{
			int temp;
			cin >> temp;
			arr.push_back({ temp, 0 });
			blocks_need.push_back({ temp, 0 });
			blocks_x.push_back({ temp, 0 });
			blocks_y.push_back({ temp, 0 });
		}

		for (int j = 0; j < N; j++)
		{
			cin >> arr[j].number;
		}

		int n, m, k;
		cin >> n >> m >> k;

		if (solution(n, m, k) == -1) { cout << -1 << endl; continue; }

		/*for (int j = 0; j < N; j++)
		{
			cout << "현재 가지고 있는 갯수: " << arr[j].number << "   필요한 갯수: " << arr[j].used << endl;
		}*/
		int j;
		for (j = N - 1; j >= 1; j--)
		{
			if (arr[j].number < arr[j].used)
			{
				int a = arr[j].size / arr[j - 1].size;
				if(a>126) { cout << -1 << endl; continue; }
				unsigned long long left = arr[j].used - arr[j].number;
				arr[j].used = arr[j].number;
				arr[j - 1].used += left * a * a * a;
			}
		}
		if (arr[0].used > arr[0].number) { cout << -1 << endl; continue; }
		for (int j = 0; j < N; j++)
		{
			cout << arr[j].used << " ";
		}cout << endl;
	}
}