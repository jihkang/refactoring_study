#include <iostream>
#include <vector>

using namespace std;

int n, cnt;

bool isPossible(int idx, vector<int> v) {
	for (int i = 0; i < idx; ++i) {
		if (v[i] == v[idx] || idx - i == abs(v[idx] - v[i]))
			return (false);
	}
	return (true);
}


void solve(int idx, vector<int>& v)
{
	if (idx == n) {
		++cnt;
		return ;
	}
	for (int i = 0; i < n; ++i) {
		v[idx] = (i);	
		if (isPossible(idx, v)) {
			solve(idx + 1, v);
		}
	}
}

int main()
{
	cin >> n;
	vector<int> v(n);
	solve(0, v);
	cout << cnt;
	return 0;
}