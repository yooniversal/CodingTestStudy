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
int N;
int check[100000];
vector<int> arr[51];
int answer;
int bfs(int rt, int del)
{
    queue<int> q;
    q.push(rt);

    check[rt] = 1;
    check[del] = 1;
    if (del == rt)return 0;
    while (!q.empty())
    {
        int n = q.front();
        int chld = 0;
        q.pop();
            for (int i = 0; i < arr[n].size(); i++)
            {
                if (check[arr[n][i]] == 0)
                {
                    q.push(arr[n][i]);
                    check[arr[n][i]] = 1;
                    chld++;
                }
            }
            if (chld == 0)answer++;
    }
    return answer;
}
int main()
{
    cin >> N;
    int root=0;

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        if (a == -1)root = i;
        else {
            arr[a].push_back(i);
            arr[i].push_back(a);
        }
    }
    int d;
    cin >> d;
    cout << bfs(root,d);
}
