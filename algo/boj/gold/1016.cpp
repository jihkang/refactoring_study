#include <iostream>

int	dp[1000001];

int eratos(long long s, long long e)
{
	long long	j;
	long long	i;
	long long	k;
	int			cnt;
	int			cnt2;

	cnt2 = 0;
	cnt = e - s + 1;
	i = 2;
	while (i * i <= e)
	{
		j = i * i;
        k = (s / j);
		k = k == 0 ? 1 : k;
		while (k * j <= e) {
			if (k * j >= s && dp[k * j - s] == 0) {
				cnt2++;
				dp[k * j - s] = 1;
			}
			k++;
		}
        ++i;
	}
	return (cnt - cnt2);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	long long n, m;
	std::cin >> n >> m;
	std::cout << eratos(n, m);
	return 0;
}