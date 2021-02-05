#include<iostream>
#include<math.h>
#include <vector>
#include <stack>
#include <map>
using namespace std;


int main()
{
	int n;
	int x, y;
	cin >> n >>x >>  y;
	vector<vector<int>> arr;
	int answer = 0;
	vector<int> temp;
	while (x != y)
	{
		x++;
		y++;
		x = x / 2;
		y = y / 2;
		answer++;
	}
	cout << answer;
}