#include <iostream>
#include <vector>

using namespace std;

int max_ = -22222222;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n;
    cin >> n;
    vector<int> arr(n + 1);
    vector<int> dp(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        max_ = max(max_, dp[i]);
	}
	cout << max_ << "\n";
	return 0;
}