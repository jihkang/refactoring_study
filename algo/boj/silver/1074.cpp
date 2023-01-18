#include <iostream>
int r, c;
int result;
using namespace std;
int solve(int n, int x, int y)
{
	
	int cnt = 0;
	int plus = (1 << (n - 1));
	if (x == r && y == c)
		return (1);
	for (int i = x; i < x + plus * 2; i += plus)
	{
		for (int j = y; j < y + plus * 2; j += plus)
		{
			if ((i + plus > r && r >= i) && (j + plus > c && c >= j))
			{
				// cout << "r : " << i << "~" << i + plus << "c : " << j << "~" << j + plus << "\n";
				// cout << cnt * plus * 2<< "\n";
				solve(n - 1, i, j);
				result += cnt * (plus * plus);
			}
			cnt++;
		}
	}
	return (result);
}

int main()
{
	int n;

	cin >> n >> r >> c;
	solve(n, 0, 0);	
	cout << result;
	return 0;
}