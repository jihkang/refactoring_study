#include <iostream>

int	k, n, m;
char	map[21][21];
int		dx[] = {0, 0, -1, 1};
int		dx2[] = {-1, 1, 0, 0};
int		dy[] = {1, -1, 0, 0};
int		dy2[] = {0, 0, 1, -1};

using namespace std;

void	initMap()
{
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			map[i][j] = 0;
		}
	}
}

void	printMap()
{
	for(int i = 0; i < n; ++i ) {
		for(int j = 0; j < m; ++j ) {
			cout<< map[i][j]; 
		}
		cout<<endl;
	}
}

int	solve(int x_, int y_, int cnt)
{
	int	x, y;
	int	x2, y2;
	if (x_ == n && y_ == m )
	{
		return (1);
	}
	if (x_ < 0 || x_ >= n || y_ < 0 || y_ >= m)
		return (0);
	if (map[x_][y_] == '#') {
		y = y_ + 1;
		x = x_;
		if (y == m)
		{
			x += 1;
			y = 0;
		}
		cnt += solve(x, y, 0);
	}
	else
	{
		cout<<"init..\n";
		for(int i = 0; i < 4; ++i) {
			x = x_ + dx[i];
			y = y_ + dy[i];
			x2 = x_ + dx2[i];
			y2 = y_ + dy2[i];
			cout<<"init2..\n";
			cout<<x << y << map[x][y]<< x2 << y2 << map[x2][y2]<< "\n";
			if ((!(x < 0 || x >= n || y < 0 || y >= m) && map[x][y] == '.') && 
					(!(x2 < 0 || x2 >= n || y2 < 0 || y2 >= m)) && map[x2][y2] == '.') {
				map[x][y] = '#';
				map[x2][y2] = '#';
				map[x_][y_] = '#';
				cnt += solve(x, y, cnt);
				map[x][y] = '.';
				map[x2][y2] = '.';
				map[x_][y_] = '.';
			}
		}
	}
	cout<<cnt;
}

int main()
{
	int	res;

	cin>>k;
	while (k--) {
		int	sx, sy;
		sx = sy = -1;
		cin>>n>>m;
		int	cnt = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				cin>>map[i][j];
				if (map[i][j] == '.') 
					++cnt;		
			}
		}
		if (cnt % 3) {
			cout<<0<<endl;
		}
		else
		{
			res = solve(0, 0, 0);
			printMap();
			initMap();
		}
	}
	return 0;
}
