#include <iostream>
#include <cstring>
#include <vector>

int	map[200002][3];
int	mx[] = {1, 0, 0};
int my[] = {0, -1, 1};

using namespace std;

void	run(int x, int y, int& cnt)
{
	if (map[x][y] != -1)
		return ;
	if (x == n)
		cnt++;
	for(int i = 0; i < 3; ++i) {
		int nx = x + mx[i];
		int ny = y + my[i];
		if (map[nx][ny] != -2) {
			run(nx, ny, cnt);
			map[nx][ny] = cnt;
		}
	}
}

int	solution(int n, vector<vector<int>> walls)
{
	int	answer = 0;
	int	i;
	for(i = 0; i < n + 1; ++i) {
		maps[i][0] = maps[i][1] = maps[i][2] = -1;
	}
	for(i = 0; i < walls.size(); ++i) {
		maps[walls[i][0]][walls[i][1]] = -2;
	}
	run(1, 1, answer);
}

int main()
{
	
	return (0);
}
