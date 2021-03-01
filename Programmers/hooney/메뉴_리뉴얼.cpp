#include <string>
#include <vector>
#include <string.h>
#include <queue>
#include<iostream>
#include<math.h>
using namespace std;
int menu_check[30];
int dfs_select[30];
vector<pair<string, int>> menu_cnt;
vector<int> menu_index;
void string_push()
{
	string str;
	for (int i = 0; i < menu_index.size(); i++)
	{
		char c = menu_index[i] + 'A';
		if (dfs_select[i] == 1)str += c;
	}
	menu_cnt.push_back(make_pair(str, 0));
}

//메뉴 숫자
void DFS(int idx, int cnt, int course_num, vector<int> mn_idx)
{
	if (cnt == course_num)
	{
		string_push();
		return;
	}

	for (int i = idx; i < mn_idx.size(); i++)
	{
		int  a = mn_idx[i];
		char c = 'A' + a;
		if (dfs_select[i] == 1) { continue; }

		dfs_select[i] = 1;
		DFS(i, cnt + 1, course_num, mn_idx);
		dfs_select[i] = 0;
	}
}

bool is_menu_in_order(string set, string order)
{
	if (set.size() > order.size())return false;
	int set_idx = 0;
	int order_idx = 0;
	while (order_idx < order.size())
	{
		if (set[set_idx] == order[order_idx])
		{
			set_idx++;
			order_idx++;
		}
		else if (set[set_idx] < order[order_idx])
		{
			return false;
		}
		else
		{
			order_idx++;
		}
		if (set_idx == set.size())return true;
	}
	return false;
}
void count_menu_in_orders(vector<string> orders)
{
	for (int i = 0; i < orders.size(); i++)
	{
		for (int j = 0; j < menu_cnt.size(); j++)
		{
			if (is_menu_in_order(menu_cnt[j].first, orders[i]))
			{
				menu_cnt[j].second++;
			}
		}
	}
}


vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;

	//들어가는 단품메뉴 정수 벡터에 인덱스 저장
	for (int i = 0; i < orders.size(); i++)
	{
		sort(orders[i].begin(), orders[i].end());
		//cout << orders[i] << endl;
		for (int j = 0; j < orders[i].size(); j++)
		{
			menu_check[orders[i][j] - 'A'] = 1;
		}
	}
	for (int i = 0; i < 30; i++)
	{
		if (menu_check[i] == 1)menu_index.push_back(i);
	}

	for (int c : course)
	{
		menu_cnt.clear();
		DFS(0, 0, c, menu_index);
		count_menu_in_orders(orders);
		int max = 0;
		for (int i = 0; i < menu_cnt.size(); i++)
		{
			if (max < menu_cnt[i].second)
			{
				max = menu_cnt[i].second;
			}
		}
		if (max < 2) { continue; }

		for (int i = 0; i < menu_cnt.size(); i++)
		{
			cout << menu_cnt[i].first << ": " << menu_cnt[i].second << endl;
			if (max == menu_cnt[i].second)
			{
				answer.push_back(menu_cnt[i].first);
			}
		}
		/*for (int i = 0; i < menu_cnt.size(); i++)
		{
			cout << menu_cnt[i].first << endl;
		}*/

	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << endl;
	}

	




	return answer;
}
int main()
{
	vector<string> orders;
	orders.push_back("XYZ");
	orders.push_back("XWY");
	orders.push_back("WXA");
	vector<int> course;
	course.push_back(2);
	course.push_back(3);
	course.push_back(4);
	solution(orders, course);
}