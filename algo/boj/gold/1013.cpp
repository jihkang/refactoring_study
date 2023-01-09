#include <iostream>
#include <string>
#include <regex>

bool solve(std::string& str)
{
	std::string test = "(100+1+|01)+";
	std::regex rx(test);
	return (regex_match(str, rx));
}

int main()
{
	int t;
	std::cin >> t;

	for (int i = 0; i < t; ++i) {
		std::string str;
		std::cin >> str;
		std::string res = (solve(str) == true) ? "YES\n" : "NO\n";
		std::cout << res;
	}
	return 0;
}