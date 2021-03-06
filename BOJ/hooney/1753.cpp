#include <stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#define MAX 10000000
using namespace std;
vector<pair<int, int>> arr[20002];
int cost[20002];
int check[20002];
int V, E;
struct compare {
	bool operator()(pair<int, int> a, pair <int, int> b)
	{
		return a.second > b.second;
	}
};
void fucking_dijsktra(int s)
{
	/*for (int i = 0; i < arr[s].size(); i++)
	{
		cost[arr[s][i].first] = arr[s][i].second;
	}*/

	priority_queue<pair<int, int>, vector<pair<int, int>>, compare>pq;
	cost[s] = 0;
	pq.push({ s,0 });

	while (!pq.empty())
	{
		int current_position = pq.top().first;
		int distance = pq.top().second;
		pq.pop();
		//cout << current_position << " " << distance << endl;
		if (distance > cost[current_position])continue;

		for (int i = 0; i < arr[current_position].size(); i++)
		{
			int next = arr[current_position][i].first;
			int nextDistance = arr[current_position][i].second + distance;
			if (nextDistance < cost[next])
			{
				cost[next] = nextDistance;
				pq.push({ next,nextDistance });
			}
		}
	}


}
int main(void)
{
	int start;
	scanf("%d %d", &V, &E);
	scanf("%d", &start);

	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		arr[a].push_back({ b,c });
	}
	for (int i = 0; i <= V; i++)
	{
		cost[i] = MAX;
	}
	fucking_dijsktra(start);
	for (int i = 1; i <= V; i++)
	{
		if (cost[i] == MAX) { printf("INF\n"); continue; }
		printf("%d\n", cost[i]);
	}
}