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
int main()
{
	int answer = 0;
	string str;
	cin >> str;
	int i;
	for (i = 0; i < str.size()-1; i++)
	{
		if (str[i] == 'c')
		{
			if (str[i + 1] == '='||str[i+1]=='-')
			{
				answer++;
				i++;
				continue;

			}
		}

		if (str[i] == 'd')
		{
			if (str[i + 1] == '-')
			{
				answer++;
				i++;
				continue;

			}

			if (i<str.size()-2&&str[i + 1] == 'z' && str[i + 2] == '=')
			{
				answer++;
				i++;
				i++;
				continue;
			}
		}

		if (str[i] == 'l')
		{
			if (str[i + 1] == 'j')
			{
				answer++;
				i++;
				continue;

			}
		}

		if (str[i] == 'n')
		{
			if (str[i + 1] == 'j' )
			{
				answer++;
				i++;
				continue;

			}
		}

		if (str[i] == 's')
		{
			if (str[i + 1] == '=')
			{
				answer++;
				i++;
				continue;
			}
		}

		if (str[i] == 'z')
		{
			if (str[i + 1] == '=')
			{
				answer++;
				i++;
				continue;
			}
		}
		answer++;
		cout << i << " ";
	}
	if (i == str.size() - 1)answer++;
	cout << answer;
}
