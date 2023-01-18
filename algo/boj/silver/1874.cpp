#include <iostream>
#include <stack>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int 						n;
	std::stack<int> s;
	std::string			str;
	int 						cnt = 0;
	
	std::cin >> n;
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> v[i];
	}
	for (int i = 0; i < n; ++i) {
		s.push(i + 1);
		str += "+\n";
		while (!s.empty() && s.top() == v[cnt]) {
			s.pop();
			str += "-\n";
			cnt++;
		}
	}
	if (!s.empty())
	{
		std::cout << "no\n";
		return 0;
	}
	std::cout <<str;
	return 0;
}