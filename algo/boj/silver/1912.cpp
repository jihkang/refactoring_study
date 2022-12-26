#include <iostream>

using namespace std;

int arr[100001];
int dp[100001];
int max_ = -22222222;

int main() 
{
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	for (int i = 1; i < n; ++i) {
		dp[i] = dp[i - 1] + arr[i];
		if (dp[i] < arr[i])
			dp[i] = arr[i];
	}
	for (int i = 0; i < n; ++i) {
		if (dp[i] > max_) {
			max_ = dp[i];
		}
	}
	cout << max_ << "\n";
	return 0;
}