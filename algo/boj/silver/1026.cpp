#include <iostream>
#include <vector>

using namespace std;

int map[2][51];
int n;
int _min;

int main()
{
	cin >> n;
	vector<int> v(n);
	vector<int> v2(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> v2[i];
	}
	sort(v.begin(), v.end());
	sort(v2.begin(), v2.end());
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += (v[i] * v2[n - 1 - i]);
	}
	cout << sum << endl;
	return 0;
}