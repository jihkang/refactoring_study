#include <iostream>
#include <vector>
#include <cmath>

int arr[1000000];

int		count(unsigned long long n)
{
	int c = 0;

	while (n >>= 1) {
		c++;
	}
	return (c);
}

bool	solve(unsigned long long n)
{
	// std::cout << n << " ";
	if (n == 2 || n == 1)
	{
		return n == 1 ? (false) : (true);
	}
	int cnt = count(n);
	if (cnt == 0)
		return false;
	else {
		unsigned long long t;
		t = (unsigned long long)1 << (cnt);
		// std::cout << t << " " << n << "\n";
		if (t == n)
		{
			return (!solve(n - (t / 2)));
		}
		return !solve(n - t);
		// std::cout << t << n - t << "\n";
		
	}
}

int main()
{
	unsigned long long	n;
	
	if (n == 1) 
		std::cout << 0;
	else
	{
		for (long long i = 1; i <= 48; ++i)
		{
			std::cout << solve(i) << "";
		}
	}
	return 0;
}