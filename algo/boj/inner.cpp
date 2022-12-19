#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int	print;

long long	count(vector<int> v, int value)
{
	int	i;
	int	sum;

	i = sum = 0;
	for(i = 0; i < v.size(); ++i) {
		sum += value / v[i];
	}
	return (sum);
}

long long	solve(vector<int> v, int s, int m, long long worst) {
	long long min = LLONG_MAX;
	long long	mid, sum;
   
	sum	= 0;	
	while (s <= worst) {
		mid = (s + worst) / 2;
		sum = count(v, mid);
		if (sum >= m) {
			worst = mid - 1;
			if (mid < min) {
				min = mid;
			}
		} else if ( sum < m ) {
			s = mid + 1;
		} 
	}
	return (min);
}

int	main()
{
	int	n, m;
	long long	max = 0;

	cin>>n>>m;
	vector<int> v(n);
	for(int i = 0; i < n; ++i) {
		cin>>v[i];
		if (max < v[i])
			max = v[i];
	}
	max *= m;
	cout<<solve(v, 0, m, max);
	return 0;
}
