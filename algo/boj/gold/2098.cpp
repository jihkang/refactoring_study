#include <iostream>

using namespace std;

#define INF 17000000

int map[16][16];
int dp[1 << 16][16];

int solve(int n, int idx, int mask)
{
	mask = mask | (1 << idx);
	if (mask == (1 << n) - 1) {
		if (map[idx][0] == 0)
			return INF;
		return (map[idx][0]);
	}
	if (dp[mask][idx] > 0) {
		return (INF);
	}
	dp[mask][idx] = INF;
	for (int i = 0; i < n; ++i) {
		if (i != idx && (mask&(1<<i))==0 && map[idx][i] > 0)
		{
			//최소 비용 갱신
			int temp = solve(n, mask, i) + map[idx][i];
			if (dp[mask][idx] > temp)
				dp[mask][idx] = temp;
		}
	}
	return (dp[mask][idx]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	int ret;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}
	ret = solve(n, 0, 0);
	if (ret == INF) {
		cout << "-1\n";
		return 0;
	}
	cout << ret;
	return 0;
}