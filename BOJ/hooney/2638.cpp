/******************************************************************************
Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.
*******************************************************************************/
#include <stdio.h>
#include <queue>
#include <iostream>
#include <vector>
#include<algorithm>
#include <string.h>
using namespace std;
int M, N;
int answer;
int arr[101][101];
int arr_check[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int cheeze_cnt()
{
	int num = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 1)num++;
		}
	}
	return num;
}
int bfs()
{
	queue<pair<int, int>> q;
	queue<pair<int, int>> q2;
	int cnt = 0;
	int num = cheeze_cnt();
	while (cheeze_cnt())
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				arr_check[i][j] = 0;
			}
		}
		cnt++;
		num = cheeze_cnt();
		q.push(make_pair(0, 0));

		while (!q.empty())
		{
			int y = q.front().first;
			int x = q.front().second;
			arr_check[y][x] = 1;

			q.pop();
			for (int k = 0; k < 4; k++)
			{
				int yy = y + dy[k];
				int xx = x + dx[k];
				if (xx < 0 || xx >= N || yy < 0 || yy >= M)continue;
				if (arr[yy][xx] == 0 && arr_check[yy][xx] == 0)
				{
					arr_check[yy][xx] = 1;
					q.push(make_pair(yy, xx));
					continue;
				}
			}
		}


		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] == 1)
				{
					int sides = 0;
					for (int k = 0; k < 4; k++)
					{
						int yy = i + dy[k];
						int xx = j + dx[k];
						if (xx < 0 || xx >= N || yy < 0 || yy >= M)continue;
						if (arr_check[yy][xx] == 1)
						{
							sides++;
						}

					}
					if (sides >= 2)
					{
						arr[i][j] = 0;
					}
				}
			}
		}

		//while (!q2.empty())
		//{
		//	int i = q2.front().first;
		//	int j = q2.front().second;
		//	arr_check[i][j] = 1;
		//	q2.pop();
		//}



	//	cout << endl;
	//	for (int i = 0; i < M; i++)
	//	{
	//		for (int j = 0; j < N; j++)
	//		{
	//			cout << arr[i][j] << " ";
	//		}
	//		cout << endl;

	//	}
	//	cout << endl;
	}

	cout << cnt ;

	return 0;
}


int main()
{
	cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;
			arr[i][j] = a;
		}
	}
	bfs();
}
