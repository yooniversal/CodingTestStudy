#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M;
int map[10][10];
int selected[10][10];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0,1,-1 };
int MAX = 0;
vector<pair<int, int>> temp;

vector<vector<pair<int, int>>> combi;

int BFS()
{
	queue<pair<int, int>> q;
	int safe_zone_size = M * N;
	int temp[10][10] = { 0 };
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (map[i][j] == 2)
			{
				q.push({ i,j });
				safe_zone_size--;
			}
			if (map[i][j] == 1)
			{
				safe_zone_size--;
			}
			temp[i][j] = map[i][j];
			//cout << temp[i][j] << " ";
		}
		//cout << endl;
	}

	//cout << safe_zone_size << endl;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (xx >= 1 && xx <= M && yy >= 1 && yy <= N && temp[yy][xx] == 0)
			{
				temp[yy][xx] = 2;
				q.push({ yy,xx });
				safe_zone_size--;
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		cout << endl;
		for (int j = 1; j <= M; j++)
		{
			cout << temp[i][j] << " ";
		}
		
	}
	cout << endl;

	cout << safe_zone_size;
	cout << endl;

	return safe_zone_size;
}
void DFS(int y, int x, int cnt)
{
	if (cnt == 3)
	{
		int t = BFS();
		if (t > MAX)MAX = t;
		return;
	}
	while (y <= N)
	{
		if (y == N && x >= M)return;
		x++;
		if (x > M) { x = 1; y++; }
		if (map[y][x] == 0&&selected[y][x]==0)
		{
			selected[y][x] = 1;
			map[y][x] = 1;
			DFS(y, x, cnt + 1);
			//cnt--;
			map[y][x] = 0;
			selected[y][x] = 0;
			if (x == M && y == N)cnt--;
		}

	}

}
int main()
{
	int k=0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			int a;
			cin >> a;
			map[i][j] = a;
			if (a == 1)k++;
		}
	}
	//cout << BFS();

	DFS(1, 0, 0);
	
	//MAX = min(MAX, M * N - k-3);
	cout << MAX;
}