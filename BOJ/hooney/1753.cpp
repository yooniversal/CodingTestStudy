#include<iostream>
#include<string.h>
#include<vector>

using namespace std;
int arr[20002][20002];
int cost[20002];
#define MAX 11
int V, E;
void minimum_cost(int curr,int curr_cost)
{
	//cout << curr;

	for (int i = 1; i <= V; i++)
	{
		//������ �ִ� �� �߿�
		if (arr[curr][i] != MAX)
		{
			//���� ������ �ִ� ��뺸�� ���� �̵��ϴ� ���� �� �̴����� ���
			if (cost[i] > curr_cost + arr[curr][i])
			{
				cost[i] = curr_cost + arr[curr][i];
			}
		}
	}
	int min=11;
	for (int i = 1; i <= V; i++)
	{
		if (arr[curr][i] == 0)continue;
		min = min > arr[curr][i] ? arr[curr][i] : min;
	}
	
	if (min == 11)return;
	//cout << min << endl;
	minimum_cost(min,cost[min]);
}
int main()
{

	cin >> V >> E;
	int start;
	cin >> start;
	//�ִ� ����� MAX�� �ʱ�ȭ
	for (int i = 1; i <= V; i++)
	{
		cost[i] = MAX;
	}

	// j->i�� ���� ��� �ʱ�ȭ
	for (int j = 1; j <= V; j++)
	{
		for (int i = 1; i <= V; i++)
		{
			arr[j][i] = MAX;
		}
		arr[j][j] = 0;
	}

	//�� ��� �Է¹ޱ�
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		arr[a][b] = c;
	}


	cost[start] = 0;
	minimum_cost(start,0);
	
	for (int i = 1; i <= V; i++)
	{
		if (cost[i] == 11) { cout << "INF" << endl; continue; }
		cout << cost[i] << endl;
	}

}