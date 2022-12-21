#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int		minCount = 1000000;

void	rotate_left(deque<int>& deq)
{
	int pop = deq.front();
	deq.pop_front();
	deq.push_back(pop);
}

void	rotate_right(deque<int>& deq)
{
	int pop = deq.back();
	deq.pop_back();
	deq.push_front(pop);
}

int		findInd(deque<int>&dq, int value)
{
	int	i;

	for (i = 0;i < dq.size(); ++i) {
		if (dq[i] == value)
			return (i);
	}
	return (0);
}

void solve(deque<int> dq, vector<int> v, int i, int& cnt)
{
	int fnd, count = 0;

	if (v.size() == i)
	{
		if (cnt < minCount) {
			minCount = cnt;
		}
		return ; 
	}
	if (dq.front() == v[i]) {
		dq.pop_front();
		i++;
		return solve(dq, v, i, cnt);
	}
	fnd = findInd(dq, v[i]);
	if (fnd > dq.size() - fnd) {
		while (dq.size() - fnd) {
			rotate_right(dq);
			cnt++;
			fnd++;
		}
	} else {
		while (fnd != 0){
			rotate_left(dq);
			cnt++;
			fnd--;
		}
	}
	solve(dq, v, i, cnt);	
}	

int main()
{
	int	n;
	int m;
	int	cnt = 0;
	cin >> n >> m ;
	deque<int> deq;
	vector<int> vec;
	for (int i = 0; i < n; ++i) {
		deq.push_back(i + 1);
	}
	for (int i = 0; i < m; ++i) {
		int value;
		cin >> value;
		vec.push_back(value);
	}
	solve(deq, vec, 0, cnt);
	cout << minCount;
	return 0;
}