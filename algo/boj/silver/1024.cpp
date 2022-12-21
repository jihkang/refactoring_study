#include <iostream>

using namespace std;

int		sigma(int sum, int l)
{
	return ((2 * sum / l) - l + 1) / 2;
}

void solve(int n, int l)
{
	if (l > 100)
	{
		cout << "-1";
		return ;
	}
	int start = sigma(n, l);
	int i;
	if (start < 0)
	{
		cout << "-1";
		return ;
	}
	if ((start + start + l - 1) * l == n * 2)
	{
		for (i = 0; i < l; ++i) {
			cout << start + i;
			if (i != l - 1)
				cout << " " ;
		}
	} else {
		solve(n, l + 1);
	}
}

int main()
{
	int n, l;

	cin >> n >> l;
	solve(n ,l);
	return 0;
}