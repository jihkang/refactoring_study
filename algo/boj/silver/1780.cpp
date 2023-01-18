#include <iostream>

using namespace std;

int	map[2187][2187];
int	result[4];

void	increase_count(int c)
{
	++result[c + 1];
}

void	solve(int n, int ox, int oy)
{
	int	c = map[ox][oy];

	if (n == 1)
	{
		increase_count(c);
		return ;
	}
	for (int i = ox; i < ox + n; ++i)
	{
		for (int j = oy; j < oy + n; ++j)
		{
			if (map[i][j] != c)
			{
				n /= 3;
				for (int k = 0; k < 3; k++) {
					for (int l = 0; l < 3; l++) {
						solve(n, ox + k * n, oy + l * n);
					}
				}
				return ;
			}
		}
	}
	increase_count(c);
}

int main()
{
	int	n;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)	{
			cin >> map[i][j];
		}
	}
	solve(n, 0, 0);
	for (int i = 0; i < 3; ++i) {
		std::cout << result[i] << "\n";
	}
	return 0;
}