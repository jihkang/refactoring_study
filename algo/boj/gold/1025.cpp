#include <iostream>
#include <cmath>

int n, m;
int map[9][9];
int _max;

bool is_square(int value) {
	if ((int)(pow((int)sqrt(value), 2)) == value)
		return (true);
	return (false);
}

void bf(int sx, int sy, int sum, int i, int j) {
    if (sx < 0 || sx >= n || sy < 0 || sy >= m) {
		return ;
	}
	sum = sum * 10 + map[sx][sy];
    if (is_square(sum) && sum > _max)
		_max = sum;
	bf(sx + i, sy + j, sum, i, j);
}

int main()
{
	std::cin >> n >> m;
	std::string str;
	for (int i = 0; i < n; ++i) {
		std::cin >> str;
		for (int j = 0; j < m; ++j) {
			map[i][j] = str[j] - '0';
		}
	}
	_max = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = -n; k <= n; ++k) {
				for (int l = -m; l <= m; ++l) {
					if (k == 0 && l == 0)
						continue ;
					bf(i, j, 0, k, l);
				}
			}
		}
	}
	std::cout << _max << "\n";
	return 0;
}