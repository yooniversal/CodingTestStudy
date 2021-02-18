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

struct point
{
    int x=0;
    int cnt=0;
    point() { x = 0; cnt = 0; }
    point(int a, int b):x(a),cnt(b)
    {
    }
};
using namespace std;
vector<int> arr[1001];
point check_bfs[1001];

int bfs(int num1,int num2)
{
    queue<int> q;
    int answer = 0;
    q.push(num1);
    check_bfs[num1].x = 1;
    check_bfs[num1].cnt = 0;

    while(!q.empty())
    {
        int temp = q.front();
        //cout << temp << " ";
        q.pop();
        //cout << temp << " ";
        if (temp == num2) return check_bfs[temp].cnt;
        for (int i = 0; i < arr[temp].size(); i++)
        {
            if (check_bfs[arr[temp][i]].x == 0)
            {
                q.push(arr[temp][i]);
                check_bfs[arr[temp][i]].x = 1;
                check_bfs[arr[temp][i]].cnt = check_bfs[temp].cnt+1;
            }
        }
    }
    return -1;
    
}
int main()
{
    
    int n, m;
    cin >> n;
    int x, y;
    cin >> x >> y;
    //fill(check_bfs, check_bfs + n + 1, false);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        sort(arr[i].begin(), arr[i].end());
    }

    cout << bfs(x, y);

    return 0;
}
