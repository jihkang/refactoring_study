#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

int map[201][201];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void	addVector(std::deque<std::vector<int>>& v, int x, int y) {
	std::vector<int> pos(3);
	pos[0] = map[x][y];
	pos[1] = x;
	pos[2] = y;
	v.push_back(pos);
}

bool	comp(std::vector<int>&v, std::vector<int>& v2) {
	return (v[0] < v2[0]);
}

void	solve(std::deque<std::vector<int>>&v,int n, int k)
{
	int cnt = 0;
	while (cnt < k) {
		int len = v.size();
		for (int i = 0; i < len; ++i) {
			std::vector<int> front = v.front();
			for (int j = 0; j < 4; ++j) {
				int x, y;
				x = dx[j] + front[1];
				y = dy[j] + front[2];
				if (x >= 1 && x <= n && y >= 1 && y <= n && map[x][y] == 0)
				{
					map[x][y] = front[0];
					addVector(v, x, y);
				}
			}
			v.pop_front();
		}
		++cnt;
	}
}

int main()
{
	int n, k;
	std::deque<std::vector<int>> v;

	std::cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			std::cin >> map[i][j];
			if (map[i][j] != 0) {
				addVector(v, i, j);
			}
		}
	}
	std::sort(v.begin(), v.end(), comp);
	int sec, fx, fy;
	std::cin >> sec >> fx >> fy ;
	solve(v, n, sec);
	// for(int i = 1; i <= n; ++i) {
	// 	for (int j = 1; j <=n; ++j) {
	// 		std::cout << map[i][j] << " ";
	// 	}
	// 	std::cout << "\n";
	// }
	std::cout << map[fx][fy] <<"\n";
	return 0;
}