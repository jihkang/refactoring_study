#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	std::cin >> n;
	priority_queue<int, std::vector<int>, greater<int>> pq;

	for (int i = 0; i < n; ++i) {
		int num;
		std::cin >> num;
		pq.push(num);
	}
	int sum = 0;
	while (pq.size()) {
		if (pq.size() == 1) {
			break ;
		}
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		sum += a + b;
		pq.push(a + b);
	}

	cout<< sum <<"\n";
	return 0;
}