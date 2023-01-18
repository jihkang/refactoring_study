#include <iostream>
#include <string.h>
#include <queue>
#include <utility>

int	map[101][101];
int dp[101][101];
int visit[101][101];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m;
int _min = 100001;

void solve(std::queue<std::pair<int, int>> que)
{
	while (!que.empty())
	{
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; ++i) {
			int _x = x + dx[i];
			int _y = y + dy[i];
			if (_x >= 0 && _x < n && _y >= 0 && _y < m) {
				if (map[_x][_y] == 1 && visit[_x][_y] == 0) {
					visit[_x][_y] = 1;
					dp[_x][_y] = dp[x][y] + 1;
					que.push(std::make_pair(_x, _y));
				}
			}
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	std::cin >> n >> m;	
	std::queue<std::pair<int, int>> que;
	for (int i = 0; i < n; ++i) {
		std::string str;
		std::cin >> str;
		for (int j = 0; j < m; ++j) {
			map[i][j] = str[j] - '0';
		}
	}
	visit[0][0] = 1;
	que.push(std::make_pair(0, 0));
	solve(que);
	std::cout << dp[n - 1][m - 1] + 1<<"\n";
	return 0;
}