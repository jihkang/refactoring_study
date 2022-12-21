#include <iostream>
#include <queue>

using namespace std;

char check[1000001];

int solve(deque<int>& dq,  int m, int cnt) {
	int len;
	int value;

	len = dq.size();
	for (int i = 0; i < len; ++i) {
		value = dq[0];
		if (value > 0 && check[value - 1] == 0)
			dq.push_back(value - 1);
		if (value < 100000 && check[value + 1] == 0)
			dq.push_back(value + 1);
		if (value <= 50000 && check[value * 2] == 0)
			dq.push_back(value * 2);
		dq.pop_front();
		check[value] = 1;
	}
	for (int i = 0; i < dq.size(); ++i) {
		if (dq[i] >= 0 && dq[i] <= 1000000)
		{
			check[dq[i]] = 1;
			if (dq[i] == m)
				return (cnt);
		}
	}
	return (solve(dq, m, cnt + 1));
}

int main()
{
	int n, m;
	int cnt = 1;
	deque<int> dq;

	cin >> n >> m;
	dq.push_back(n);
	if (n == m)
	{
		cout << '0' << "\n";
		return 0;
	}
	cout << solve(dq, m, cnt);
	return 0;
}