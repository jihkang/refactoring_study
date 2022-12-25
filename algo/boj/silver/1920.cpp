#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

int solve(int s, int e, int fnd)
{
	if (s > e)
		return (0);
	int mid = (s + e) / 2;
	if (v[mid] == fnd) {
		return 1;
	} else if (v[mid] > fnd) {
		return solve(s, mid - 1, fnd);
	}
	return solve(mid + 1, e, fnd);
}

int main()
{
	int n;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int m;
	cin >> m;
	int fnd;
	for (int i = 0; i < m; ++i) {
		cin>> fnd;
		cout << solve(0, n - 1, fnd) << endl;
	}
	return 0;
}