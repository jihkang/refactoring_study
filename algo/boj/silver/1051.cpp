#include <iostream>

using namespace std;

int MAX = 1;
int n, m;
int map[51][51];

int solve(int x, int y)
{
	int dist = 1;
	for (int i = n - 1; i > x; --i) {
		dist = i - x;
		if (y + dist >= 0 && y + dist < m && 
			map[i][y]  == map[x][y] &&
			map[x][y + dist] == map[x][y] &&
			map[i][y + dist] == map[x][y]) {
			
			return ((dist + 1) * (dist + 1));
		}
	}
	return (dist);
}

int main()
{
	string str;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin>> str;
		for (int j = 0; j < m; ++j) {
			map[i][j] = (int)str[j] - '0';
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j){
			int tmp = solve(i, j); 
			if (MAX < tmp)
				MAX = tmp;	
		}
	}
	cout << MAX << endl;
	return 0;
}