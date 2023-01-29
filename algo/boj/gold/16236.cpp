#include <iostream>
#include <utility>
#include <deque>
#include <algorithm>

using namespace std;

int	n, map[21][21];
int	foods[100000];
int	cnt, scnt;
int	eatcnt;
pair<int, int> p;

bool	comp(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2)
{
	pair<int, int> v1 = p1.second;
	pair<int, int> v2 = p2.second;
	if (abs(p1.second.first - p.first) + abs(p1.second.second - p.second) < 
		abs(p2.second.first - p.first) + abs(p2.second.second - p.second))
		return (true);
	if (abs(p1.second.first - p.first) + abs(p1.second.second - p.second) == 
		abs(p2.second.first - p.first) + abs(p2.second.second - p.second))	
		{
			if (p1.first == p2.first)
			{
				return p1.second < p2.second;
			}
			return p1.first < p2.first;
		}
	else
		return false;
}

void	solve(deque<pair<int, pair<int, int>>>& food)
{
	while (true)
	{
		if (food.empty())
			break ;
		sort(food.begin(), food.end(), comp);
		pair<int, pair<int, int>> f = food.front();
		cnt += abs(p.first - f.second.first) + abs(p.second - f.second.second);
		p.first = f.second.first;
		p.second = f.second.second;
		eatcnt++;
		food.pop_front();
		if (eatcnt == scnt)
		{
			scnt++;
			eatcnt = 0;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (map[i][j] > 0 && map[i][j] < scnt) {
					food.push_back(make_pair(map[i][j], make_pair(i, j)));
					map[i][j] = 0;
				}
			}
		}
	}
	cout << cnt << "\n";
}

int main()
{
	deque<pair<int, pair<int, int>>> food;
	scnt = 2;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 9)	{
				p.first = i;
				p.second = j;
			}
			else if (map[i][j] != 0 && map[i][j] < scnt) {
				food.push_back(make_pair(map[i][j], make_pair(i, j)));
				map[i][j] = 0;
			}
		}
	}
	solve(food);	
	return 0;
}