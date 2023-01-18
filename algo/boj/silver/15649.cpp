#include <iostream>
#include <deque>

void solve(int n, int m, std::deque<int>& dq, int cnt, int selected) {
	if (m == cnt) {
		for (int i = 0; i < dq.size(); ++i) {
			std::cout<< dq[i]<< " ";
		}
		std::cout << "\n";
		return ;
	}	
	for (int i = 1; i <= n; ++i) {
		if (selected & (1 << i))
			continue ;
		selected = selected | (1 << i);
		dq.push_back(i);
		solve(n, m, dq, cnt + 1, selected);
		dq.pop_back();
		selected = selected & ~(1 << i);
	}
}

int main()
{
	int n, m, cur = 0;
	std::deque<int> dq;
	std::cin >> n >> m;
	solve(n, m, dq, 0, cur);
	return 0;
}