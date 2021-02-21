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
int arr[100000][3];

int main()
{
    cin >> N;
    arr[0][0] = 1;
    arr[0][1] = 1;
    arr[0][2] = 1;

    for (int i = 1; i < N; i++)
    {
        arr[i][0] = arr[i - 1][1] + arr[i - 1][2];
        arr[i][1] = arr[i - 1][0] + arr[i - 1][2];
        arr[i][2] = arr[i - 1][1] + arr[i - 1][2] + arr[i-1][0];
        arr[i][0] = arr[i][0] % 9901;
        arr[i][1] = arr[i][1] % 9901;
        arr[i][2] = arr[i][2] % 9901;
    }
    cout << (arr[N - 1][0] + arr[N - 1][1] + arr[N - 1][2])%9901;
}
