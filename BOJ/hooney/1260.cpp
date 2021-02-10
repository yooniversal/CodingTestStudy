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
using namespace std;
vector<int> arr[1001];
bool check_dfs[1001];
bool check_bfs[1001];
void dfs(int index)
{
    check_dfs[index] = true;
    cout << index << " ";
    for (int i = 0; i < arr[index].size(); i++) {
        int next = arr[index][i];

        if (!check_dfs[next]) { //방문하지 않았다면 DFS() 호출
            dfs(next);
        }
    }
}
void BFS(int V) {
    queue<int> q; //Queue 생성
    q.push(V); //초기 시작점 저장
    check_bfs[V] = true; //초기 방문 체크

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int i = 0; i < arr[current].size(); i++) {
            int next = arr[current][i];

            if (!check_bfs[next]) {
                check_bfs[next] = true;
                q.push(next);
            }
        }
    }
}

void bfs(int index)
{

}
int main()
{
    int N, M, V;
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for (int i = 1; i <= 1000; i++)
    {
        sort(arr[i].begin(), arr[i].end());
    }

    dfs(V);
    cout << endl;
    BFS(V);

    return 0;
}
