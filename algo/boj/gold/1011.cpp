#include <iostream>

using namespace std;

long long solve(long long dist)
{
    long long cnt = 0;
	if (dist == 0) {
		return (cnt);
	}
    while (true) {
		if (cnt * (cnt + 1) >= dist)
			break ;
		cnt++;
    }
    if (dist <= cnt * cnt)
		return (cnt * 2 - 1);
	return (cnt * 2);
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int x, y, cnt = 0;
		cin >> x >> y;
		cout << solve(y - x) << "\n";
	}
	return 0;
}