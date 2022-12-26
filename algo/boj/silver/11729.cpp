#include <iostream>

using namespace std;

int dp[21];

void solve(int n, int a_, int b_, int c_)
{
	cout << a_ << " " << b_ << " " << c_ << "\n";
	if (n == 1) {
		cout << a_ << " " << c_ << "\n";
	}
	else {
		solve(--n, a_, c_, b_); 	
		solve(n, b_, a_, c_);
	}
}

int main()
{
	int n;
	cin>> n;
	dp[0] = 1;
	for (int i = 1; i < n; ++i)  {
		dp[i] = dp[i - 1] * 2 + 1;
	}
	cout << dp[n - 1] << "\n";
	solve(n,1,2,3);
	return 0;
}