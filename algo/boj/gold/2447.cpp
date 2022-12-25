#include <iostream>

using namespace std;

char map[2150][2150] = {'.'};

void solve(int x, int y, int n) {
	int depth = n / 3;
	if (depth == 1) {
		for (int i = x; i < x + 3; ++i) {
			for (int j = y; j < y + 3; ++j) {	
				if (i == x + 1 && j == y + 1) {
					map[i][j] = ' ';
					continue ;
				}
				map[i][j] = '*';
			}
		}
		return ;
	}
	for (int i = x; i < x + n; i += depth) {
		for (int j = y; j < y + n; j += depth) {
			if (i == x + depth && j == y + depth) {
				for (int k = i; k < i + depth; ++k) {
					for (int l = j; l < j + depth; ++l) {
						map[k][l] = ' ';
					}
				}
			} else {
				solve(i, j, depth);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	solve(0, 0, n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << map[i][j];
		}
		cout << "\n";
	}
	return 0;
}