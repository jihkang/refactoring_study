#include <iostream>
#include <vector>

using namespace std;

int	ret = 1000;

int	sw[10][5] = {
	{0, 1, 2, -1, -1},
	{3, 7, 9, 11, -1},
	{4, 10, 14, 15, -1},
	{0, 4, 5, 6, 7},
	{6, 7, 8, 10, 12},
	{0, 2, 14, 15, -1},
	{3, 14, 15, -1, -1},
	{4, 5, 7, 14, 15},
	{1, 2, 3, 4, 5},
	{3, 4, 5, 9, 13}
};

bool	check(int map[])
{
	for(int i = 0; i < 16; ++i) {
		if (map[i] != 12)
			return (false);
	}
	return (true);
}

void	timeChange(int map[], int swInd) {
	for(int i = 0; i < 5; ++i) {
		int	ind = sw[swInd][i];
		if (ind != -1) {
			map[ind] = map[ind] + 3;
			if (map[ind] == 15)
				map[ind] = 3;
		}
	}
}

void	printTime(int map[]) {
	for(int i = 0; i < 16; ++i) {
		cout<<map[i] << " ";
	}
	cout<<endl;
}

void	solve(int map[], int idx, int cnt)
{
	if (check(map) == true)
	{
		if (ret > cnt)
			ret = cnt;
		cout<<cnt;
	}
	if (idx == 10)
		return ;
	for(int i = 0; i < 4; ++i) {
		solve(map, idx + 1, cnt + i);
		timeChange(map, idx);
		printTime(map);
	}
}

int main()
{
	int	n, m;

	cin>>n;
	for(int i = 0; i < n; ++i) 
	{
	int	map[17];
		for(int j = 0; j < 16; ++j) {
			cin>>map[j];
		}
		solve(map, 0, 0);
		cout<<ret;
		ret = 1000;	
	}
}
