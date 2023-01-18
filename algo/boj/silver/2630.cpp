#include <iostream>

int 	n;
char	map[129][129];
bool	visited[129][129];
int		white;
int		blue;

using namespace std;

void	solve(int x, int y, int c)
{
	char	first;
	bool	cont = false;

	if (c == 1)
	{
		if (map[x][y] == '1')
			blue++;
		else
			white++;
		return;
	}
	first = map[x][y];
	for (int i = x; i < x + c; ++i)
	{
		for (int j = y; j < y + c; ++j)
		{
			if (first != map[i][j])
			{
				solve(x, y, c / 2);
				solve(x + c /2, y, c/ 2);	
				solve(x, y + c /2, c / 2);
				solve(x + c /2, y + c / 2, c / 2);
				return ;
			}
		}
	}
	if (map[x][y] == '1')
		blue++;
	else
		white++;
	return;	
}

int main()
{
	cin >> n;
	for (int i = 0;i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}
	solve(0, 0, n);
	cout << white << "\n" << blue << "\n";
	return 0;
}