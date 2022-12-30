#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool comp(std::string& a, std::string& b) {
	if (a.length() == b.length())
		return a.compare(b) < 0;
	else {
		return a.length() < b.length();
	}
}

int main()
{
	int n;
	std::vector<std::string>v;
	std::cin>> n;
	for (int i = 0; i < n; ++i) {
		std::string input;
		std::cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end(), comp);
	auto lt = unique(v.begin(), v.end());
	for (auto it = v.begin(); it != lt; ++it) {
		cout << *it << "\n";
	}
	return 0;
}