#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> minQue;
	priority_queue<int> maxQue;
	int n;
	int num;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> num;
		if (maxQue.size() > minQue.size()) {
			minQue.push(num);
		} else {
			maxQue.push(num);
		}
		if (!minQue.empty()) {
			if (maxQue.top() > minQue.top()) {
				int _min = minQue.top();
				minQue.pop();
				int _max = maxQue.top();
				maxQue.pop();
				minQue.push(_max);
				maxQue.push(_min);
			}
		}
		std::cout << maxQue.top() << "\n";
	}
	return 0;
}