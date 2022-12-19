#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

long long pb;
int	s = 0;
int	e;
int	i1, i2;
int	cnt;

void	solve(vector<long long>& v) {
	long long max = -1;
	while (s < e) {
		if (v[s] + v[e] == pb) {
			if (abs(v[s] - v[e]) > max) {
				max = abs(v[s] - v[e]);
				i1 = s;
				i2 = e;
			}
			cnt++;
			e--;
		}
		else if (v[s] + v[e] < pb) {
			s++;
		}
		else if (v[s] + v[e] > pb) {
			e--;
		}
	}
	if (cnt == 0) {
		cout <<"danger"<<endl;
	} else {
		cout<<"yes "<<v[i1] << " "<<v[i2];
	}
}

int main() {
	int n;

	while (true) {
		cin>>pb;
		s = 0;
		cnt = 0;
		i1 = i2 = 0;
		if (cin.eof())
			break;
		pb *= (10000000);
		cin>>n;
		vector<long long> v(n);
		for(int i = 0; i < n; ++i) {
			cin>>v[i];
		}
		sort(v.begin(), v.end());
		e = n - 1;
		solve(v);
	}
	return 0;
}
