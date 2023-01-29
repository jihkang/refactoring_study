#include <iostream>
#include <cmath>

int s, n, k, r1, r2, c1, c2;

int value(int x, int y) {
	int	_max = pow(n, s);
	while((_max /= n) != 0) {
		if (x >= _max * (n - k) / 2 && x < _max * (n + k) / 2 &&
			y >= _max * (n - k) / 2 && y < _max * (n + k) / 2)
			return (1);
		x %= _max;
		y %= _max;
	}
	return (0);
}

int main()
{
	std::cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;
	for (int i = r1; i <= r2; ++i) {
		for (int j = c1; j <= c2; ++j) {
			std::cout << value(i, j);
		}
		std::cout <<"\n";
	}
	return 0;
}