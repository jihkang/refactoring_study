#include <iostream>
#include <vector>

using namespace std;

int max2;

void solve(vector<pair<int, int>>& delay, vector<int>& v, int m)
{
	for (int i = 0; i < delay.size(); ++i) {
		if (delay[i].second == m) {
			
		}
	}
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, k, m;
		max2 = 100000000;
		cin >> n >> k;
		vector<int> v(n);
		vector<pair<int, int>> delay;
		for (int j = 0; j < n; ++j) {
			cin>>v[i];
		}
		for (int j = 0; j < k; ++j) {
			pair<int, int> p;
			cin>>p.first >> p.second;
			delay.push_back(p);
		}
		cin>> m;
		solve(delay, v, m);
	}	
	return 0;
}