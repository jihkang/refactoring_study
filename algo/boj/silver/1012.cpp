#include <iostream>
#include <vector>

using namespace std;

int map[51][51];
int n, m, l;

int mx[] = {0, 0, 1, -1};
int my[] = {1, -1, 0, 0};

void move(int x, int y)
{
    for (int i = 0; i < 4; ++i) {
		int _x = x + mx[i];
		int _y = y + my[i];
	    if (_x >= 0 && _x < n && _y >= 0 && _y < m)
    	{
		    if (map[_x][_y] == 1)
            {
           		map[_x][_y] = 2;
        	    move(_x, _y);
	    	}
	    }
    }
}

int solve(vector<vector <int>> v)
{
	int cnt = 0;
	int	i;
	for (i = 0; i < v.size(); ++i) {
		if (map[v[i][0]][v[i][1]] == 1)
		{
			++cnt;
            map[v[i][0]][v[i][1]] = 2;
			move(v[i][0], v[i][1]);
		}
	}
	return (cnt);
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> n >> m >> l;
		for (int j = 0; j < 50; ++j) {
			for (int k = 0; k < 50; ++k) {
				map[j][k] = 0;
			}
		}
		vector<vector<int>> v(l);	
		for (int j = 0; j < l; j++) {
			vector<int> p(2);
			cin >> p[0] >> p[1];
			map[p[0]][p[1]] = 1;
			v[j] = p;
		}
		cout << solve(v) << endl;
	}
	return 0;
}