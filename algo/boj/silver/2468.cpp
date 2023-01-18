#include <iostream>

using namespace std;

int 	map[101][101];
bool	visited[101][101];
int 	result, n, _max, cntArray;
int		arr[10000][2];
int		dx[] = {0, 0, -1, 1};
int		dy[] = {1, -1, 0, 0};

void	bf(int x, int y, int value)
{
	int i, j;

	for (int i = 0; i < 4; ++i) {
		int _x = x + dx[i];
		int _y = y + dy[i];
		if (_x >= 0 && _x < n && _y >= 0 && _y < n && visited[_x][_y] == false) {
			if (map[_x][_y] > value)
			{
				visited[_x][_y] = true;
				arr[cntArray][0] = _x;
				arr[cntArray++][1] = _y;
				bf(_x, _y, value);
			}
		}
	}
}

void	solve(int height)
{
	int i, j;
	int	cnt = 0;

	if (height >= _max)
		return ;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if (height < map[i][j] && visited[i][j] == false) {
				cnt++;
				bf(i, j, height);
			}
		}
	}
	if (cnt > result)
		result = cnt;
	for (i = 0; i < cntArray; ++i) {
		visited[arr[i][0]][arr[i][1]] = false;
	}
	cntArray = 0;
	solve(height + 1);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
			if (_max < map[i][j])
				_max = map[i][j];
		}
	}
	solve(0);
	cout << result <<"\n";
	return 0;
}