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
int arr[101][101];
int M,N;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

bool is_in(int x,int y)
{
    if (x < 0 || x >= M)return false;
    if (y < 0 || y >= N)return false;
    return true;
}
void dfs(int x, int y)
{
    if (arr[y][x] == 0)return;
    arr[y][x] = 0;
    for (int r = 0; r < 4; r++)
    {
        int yy = y + dy[r];
        int xx = x + dx[r];
        if (is_in(xx, yy))dfs(xx, yy);
    }
}
int bfs(int arr[][101])
{
    queue<pair<int,int>> q;
    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 0)continue;

            else
            {
                dfs(j, i);
                answer++;
            }
        }
    }
    return answer;
}
int main()
{
    
    int T,K;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        cin >> M >> N >> K;
        for (int i = 0; i < K; i++)
        {
            int a, b;
            cin >> a >> b;
            arr[b][a] = 1;
        }
        cout << bfs(arr) << endl;
        memset(arr, 0, sizeof(arr));
    }
    

    return 0;
}
