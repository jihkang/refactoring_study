#include <iostream>
#include <vector>

using namespace std;

int dp[101][100001];

void solve(vector<vector<int>>& v, int n, int w) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= w; ++j) {
			if (j + v[i - 1][0] <= w) {
				dp[i][j + v[i - 1][0]] = max(
					dp[i - 1][j + v[i - 1][0]], dp[i - 1][j] + v[i - 1][1]
				);
			}
		}	
		for (int j = 1; j <= w; ++j) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j]);
		}
	}
}

int main()
{
	int n, k;
	vector<vector<int>> vec;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int w, v;
		vector<int> p;
		cin >> w >> v;
		p.push_back(w);
		p.push_back(v);
		vec.push_back(p);	
	}
	solve(vec, n, k);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << dp[n][k] << endl;
	return 0;
}