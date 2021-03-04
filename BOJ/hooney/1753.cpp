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
		//엣지가 있는 것 중에
		if (arr[curr][i] != MAX)
		{
			//현재 가지고 있는 비용보다 지금 이동하는 것이 더 이덕젹일 경우
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
	//최단 비용을 MAX로 초기화
	for (int i = 1; i <= V; i++)
	{
		cost[i] = MAX;
	}

	// j->i로 가는 비용 초기화
	for (int j = 1; j <= V; j++)
	{
		for (int i = 1; i <= V; i++)
		{
			arr[j][i] = MAX;
		}
		arr[j][j] = 0;
	}

	//각 노드 입력받기
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