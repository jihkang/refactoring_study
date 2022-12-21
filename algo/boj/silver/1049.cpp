#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1 package 6;

int solve(int pack, int nor, int n)
{
	int res;

	if (nor > pack) {
		if (n % 6 != 0)
			n = n / 6 + 1;
		else
			n = n / 6;
		return (n * pack);
	} else {
		if (nor * 6 < pack) {
			pack = nor * 6;
			res = n * nor; 
		} else {
			res = (n / 6)  *pack;
			res += (nor * (n % 6) > pack) ? pack : nor * (n % 6);
		}
		return res;
	}
}

int main()
{
	int	n, m;
	cin >> n >> m;
	int minP = 2000, minN = 2000;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		if (minP > x) {
			minP = x;
		}
		if (minN > y) {
			minN = y;
		}
	}
	cout << solve(minP, minN, n);
	return 0;
}