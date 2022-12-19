#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void bruteForce(vector<int>& v, int v_size,  vector<int>& weg, int idx, int sum, int max) {
	if (idx >= v_size) {
		if (sum + v[idx] <= max) {
			weg.push_back(sum + v[idx]);
		}
		return;
	}
	if (sum + v[idx] == max) {
		weg.push_back(sum + v[idx]);
		return ;
	}
	if (sum + v[idx] > max)
		return ;
	bruteForce(v, v_size, weg, idx + 1, sum + v[idx], max);
	bruteForce(v, v_size, weg, idx + 1, sum, max);
}

int	solve(vector<int>& v, vector<int>& v2, int max)
{
	int s1, s2;
	int	len1, len2;
	int	count;
	int	mid;
	count = 0;
	s1 = s2 = 0;
	len1 = v.size();
	while (s1 < len1)
	{
		int i, mid;
		len2 = v2.size();
		while (s2 <= len2) {
			mid = (s2 + len2) / 2;
			if (v2[mid] + v[s1] > max) {
				len2 = mid - 1;
			} else if (v2[mid] + v[s1] <= max) {
				s2 = mid + 1;
			}
		}
		count += mid;
		s1++;
	}
	return (count);
}

int main() {
	int n, c;/*{{{*/
	int i, j;
	cin>>n>>c;
	vector<int> v;
	vector<int> v2;
	v.resize(n / 2);
	v2.resize(n - n / 2);
	for(i = 0; i < n / 2; ++i) {
		cin>>v[i];
	}
	for(j = i; j < n; ++j) {
		cin>>v2[j - i];
	}
   	vector<int> v3, v4;
	bruteForce(v, v.size(), v3, 0, 0, c);
	bruteForce(v2, v2.size(), v4, 0, 0, c);
	sort(v4.begin(), v4.end());
	cout<<solve(v3, v4, c);
	return 0;/*}}}*/
}
