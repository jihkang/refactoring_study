#include <iostream>

int	order[2][100001];
int	n;



int main() {
	std::cin >> n;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cin >> order[i][j];
		}
	}
	
	return 0;
}