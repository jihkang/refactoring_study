#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void bruteForce(vector<int>& v, int v_size,  vector<int>& weg, int idx, int sum, int max) {
	if (sum > max)
		return ;
	if (idx == v_size) {
		if (sum <= max)
			weg.push_back(sum);
		return;
	}
	bruteForce(v, v_size, weg, idx + 1, sum + v[idx], max);
	bruteForce(v, v_size, weg, idx + 1, sum, max);
}

int	solve(vector<int>& v, vector<int>& v2, int max)
{
	int s1, s2;
	int	len1, len2;
	int	count;
    
	count = 0;
	s1 = 0;
	len1 = v.size();
	while (s1 < len1)
	{
		int mid;
        int save = 0;
		len2 = v2.size() - 1;
        s2 = 0;
		while (s2 <= len2) {
			mid = (s2 + len2) / 2;
			if (v2[mid] + v[s1] > max) {
				len2 = mid - 1;
			} else if (v2[mid] + v[s1] <= max) {
                save = mid + 1;
				s2 = mid + 1;
			}
		}
			count += save;
		s1++;
	}
	return (count);
}

int main() {
	int n, c;
	int i, j;
	cin>>n>>c;
	vector<int> v;
	vector<int> v2;
	v.resize((n + 1) / 2);
	v2.resize(n - (n + 1) / 2);
	for(i = 0; i < (n + 1) / 2; ++i) {
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
	return 0;
}
