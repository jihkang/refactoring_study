#include <iostream>
#include <cstring>

void	printDefault() {
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

void	printUpper(std::string str) {
	for (unsigned long i = 0; i < str.length(); ++i) {
		str[i] = toupper(str[i]);
	}
	std::cout << str;
}

int main(int ac, char **av)
{
	if (ac != 1) {
		for (int i = 1; i < ac; ++i) {
			printUpper(av[i]);
		}
	} else {
		printDefault();
	}
	return (0);
}
