#include <iostream>
#include <deque>

int n, m;

void solve(int cur, int idx, std::deque<int>& dq) {
	if (idx == m) {
		for (int i = 0; i < dq.size(); ++i) {
			std::cout << dq[i] << " ";
		}
		std::cout << "\n";
		return ;
	}
	for (int i = cur + 1; i <= n; ++i) {
		dq.push_back(i);
		solve(i, idx + 1, dq);
		dq.pop_back();
	}
}

int main()
{
	std::cin >> n >> m;	
	std::deque<int> dq;
	solve(0, 0, dq);
	return 0;
}