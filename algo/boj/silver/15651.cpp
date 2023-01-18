#include <iostream>
#include <deque>

void solve(int n, int m, int idx, std::deque<int>& dq)
{
	if (idx == m) {
		for (int i = 0; i < dq.size(); ++i) {
			std::cout << dq[i] << " ";
		}
		std::cout << "\n";
		return ;
	}
	for (int i = 0; i < n; ++i){
		dq.push_back(i + 1);
		solve(n, m, idx + 1, dq);
		dq.pop_back();
	}	
}

int main()
{
	
	std::deque<int> dq;
	int n, m;
	std::cin >> n >> m;
	solve(n, m, 0, dq);
	return 0;
}