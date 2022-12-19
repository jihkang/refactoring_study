#include <iostream>

using namespace std;

int nc[31][31];

unsigned long long combine(int x, int y)
{
	if (nc[x][y] != 0)
		return (nc[x][y]);
	if (y == x || x == 0)
	{
		return 1;
	}
	nc[x][y] = combine(x - 1, y - 1) + combine(x, y - 1);
	return (nc[x][y]);
}

int main()
{
	int	n, x, y;

	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> x >> y;
		cout << combine(x, y) << endl;
	}
	return 0;
}
