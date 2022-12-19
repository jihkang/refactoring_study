#include <iostream>
#include <algorithm>

using namespace std;

int	house[101];

int	get_max(int n, int cur)
{
	int	i;
	int	_max = 0, tmp = -1;

	for(i = 0; i < n; ++i) {
		if (i == cur)
			continue ;
		if (house[i] > _max)
		{
			_max = house[i];
			tmp = i;
		}
	}
	return (tmp);
}


int	solve(int n)
{
	int	cnt = 0;
	int	biggest, bigger;

	while (true)
	{
		biggest = get_max(n, -1);
		bigger = get_max(n, biggest);
		if (biggest == -1)
			break ;
		house[biggest]--;
		if (bigger != -1)
			house[bigger]--;
		++cnt;
	}
	return (cnt);
}

int main()
{
	int	n;
	int	cnt;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> house[i];
	}
	cnt = solve(n);
	if (cnt >= 1441) 
		cnt = -1;
	cout << cnt << endl;
	return 0;
}
