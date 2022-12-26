#include <iostream>

using namespace std;

int _max = -1;

int map[500][500];
int dp[501][501];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			cin >> map[i][j];
		}
	}
	dp[0][0] = map[0][0];
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j] + map[i][j];
			} else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + map[i][j];
			} else {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + map[i][j];
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (dp[n - 1][i] > _max) {
			_max = dp[n - 1][i];
		}
	}
	cout << _max << endl;
}