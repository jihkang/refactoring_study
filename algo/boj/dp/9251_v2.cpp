#include <iostream>

using namespace std;

int	dp[1001][1001];
int	cnt;
int	m;
int s_size;
int s2_size;

void	solve(string s, string s2, int x, int y, int cnt)
{
	for(int i = x; i < s_size; ++i) {
		for(int j = y; j < s2_size; ++j) {
			dp[i][j] = max(max(dp[i - 1][j - 1] + (s[i] == s[j]),dp[i -1][j]), dp[i][j - 1]);
		}
	}
}

int main()
{
	string str, str2;
	m = -1;
	cin>>str>>str2;
    s_size = str.size();
    s2_size = str2.size();
	solve(str, str2, 0, 0, 0);
	cout<<dp[s_size - 1][s2_size - 1];
	return (0);
}
