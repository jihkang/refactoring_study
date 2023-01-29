#include <iostream>
#include <deque>
#include <utility>
#include <vector>

int map[101][101][101];

int dx[] = {0, 0, 1, -1, 0, 0};
int dy[] = {1, -1, 0, 0, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

int cnt = -1;
int n, m, o;

bool checkMap() {
	for (int i = 0; i < o; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < n; ++k) {
				if (map[j][k][i] == 0) {
					return true;
				}
			}
		}
	}	
	return false;
}

void printMap() {
	for (int i = 0; i < o; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < n; ++k) {
				std::cout << map[m][j][k] << " ";
			}
			std::cout << "\n";
		}
	}
	std::cout<< "\n\n";
}

void solve(std::deque<std::vector<int>>& pos)
{
	if (pos.empty())
	{
		if (checkMap() == true)
			std::cout << "-1";
		else
			std::cout << cnt << "\n";
		return ;
	}
	int len = pos.size();
	for (int i = 0; i < len; ++i) {
		std::vector<int> p = pos.front();
		for (int j = 0; j < 6; ++j) {
			int x = p[0] + dx[j];
			int y = p[1] + dy[j];
			int z = p[2] + dz[j];
			if (z >= 0 && z < o && x >= 0 && x < m && y >= 0 && y < n)
			{
				if (map[x][y][z] == 0)
				{
					std::vector<int> v;
					v.push_back(x);
					v.push_back(y);
					v.push_back(z);
					map[x][y][z] = 1;
					pos.push_back(v);
				}		
			}
		}
		pos.pop_front();
	}
	++cnt;
	solve(pos);
}

int main()
{
	std::deque<std::vector<int>> pos;
	std::cin >> n >> m >> o;
	for (int i = 0; i < o; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < n;++k) {
				std::cin >> map[j][k][i];
				if (map[j][k][i] == 1) {
					std::vector<int> v;
					v.push_back(j);
					v.push_back(k);
					v.push_back(i);
					pos.push_back(v);
				}
			}
		}
	}
	solve(pos);
	return 0;
}