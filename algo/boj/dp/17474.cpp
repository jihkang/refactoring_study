#include <iostream>

using namespace std;

int	rgb[3][1003];
int	dp[3][1003];

void	solve(int n)
{

}

int main()
{
	int	n;

	cin>>n;
	for(int i = 0; i < n; ++i)
		cin>>rgb[0][i]>>rgb[1][i]>>rgb[2][i];
	set_dp(n);
	return 0;
}
