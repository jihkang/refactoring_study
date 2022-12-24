#include <iostream>

using namespace std;

int dp[301];

int main()
{
	int n;
	int num[301] = {0,};

	cin >> n;
	for (int i = 1; i <= n; ++i){
		cin >> num[i];
	}
	dp[0] = num[0];
	dp[1] = num[1] + num[0];
	dp[2] = num[1] + num[2];
	for (int i = 3; i <= n; ++i) {
		dp[i] = max(
			dp[i - 2] + num[i], 
			dp[i - 3] + num[i] + num[i - 1]
		);
	}
	cout << dp[n];
}