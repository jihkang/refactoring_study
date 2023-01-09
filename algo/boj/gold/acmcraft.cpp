#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int max2;
int dp[100001];

int solve(vector<pair<int, int>>& v, vector<int>& delay, int m) {
	vector<int> q;
	int i;
	int sum = 0;
	for (i = 0; i < v.size(); ++i) {
		if (v[i].first == m)
			continue ;
		if (dp[v[i].first] == 0) {
			dp[v[i].first] = v[i].second;
			q.push_back(v[i].first);
		}	else if (delay[dp[v[i].first]] > delay[v[i].second]) {
			dp[v[i].first] = v[i].second;
		}
	}
	for (i = 0; i < q.size(); ++i) {
		
	}
	cout << sum << "\n";
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, k, m;
		max2 = 100000000;
		cin >> n >> k;
		vector<int> delay(n);
		vector<pair<int, int>> v; 
		for (int j = 0; j < n; ++j) {
			cin>>delay[j];
		}
		for (int j = 0; j < k; ++j) {
			pair<int, int> p;
			cin>>p.first >> p.second;
			v.push_back(p);
		}
		cin>> m;
		solve(v, delay, m);
	}	
	return 0;
}