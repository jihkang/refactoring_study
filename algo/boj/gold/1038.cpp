#include <iostream>
#include <string.h>
#include <math.h>



void	solve(long long cur, long long n, long long cnt) 
{
	if (cur >= 9876543210 || n > 1000000) {
		std::cout << -1;
		return ;
	}
	std::string str;
	while (cur <= 9876543210 && n > cnt) {
		str = std::to_string(cur);
		bool isDecrease = true;
		int increaseIndex = 0;
		char c = str[0];
		for (int i = 1; i < str.size(); ++i) {
			if (c <= str[i]) {
				isDecrease = false;
				increaseIndex = i;
				break ;
			}
			c = str[i];
		}
		if (isDecrease) {
			cnt++;
			if (cnt == n)
			{
				std::cout << cur << "\n";
				return ;
			}
			cur++;
		}
		else {
			cur += pow(10, str.size() - increaseIndex) \
				- cur % (long long)pow(10, (str.size() - increaseIndex));
			// cnt++;
		}
	
	}
	std::cout << "-1\n";
}

int main()
{
	long long n;

	std::cin >> n;
	if (n == 0 || n == 1)
	{
		std::cout << n << "\n";
		return 0;
	}
	// for (int i = 1; i <= 50; ++i) {
		// std::cout << i << " : ";
		solve(1, n, 0);
	// }
	return 0;
}