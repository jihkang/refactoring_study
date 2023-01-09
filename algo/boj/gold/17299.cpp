#include <iostream>
#include <stack>

int n;
int arr[1000001];
int sol[1000001];
int	res[1000001];

int main()
{
	std::cin >> n;
	std::stack<int> s;
	int i, j;
	for (i = 0; i < n; ++i) {
		std::cin >> arr[i];
		++sol[arr[i]];
	}
	for (i = n - 1; i >= 0; --i) {
		int num = arr[i];
		int comp = sol[arr[i]];
		while (!s.empty())
		{
			int num2 = arr[s.top()];
			int cur2 = sol[num2]; 
			if (cur2 > comp)
				break ;
			else
				s.pop();
		}
		res[i] = s.empty() ? -1 : arr[s.top()];
		s.push(i);
	}
	for (int i = 0; i < n;  ++i) {
		std::cout << res[i] << " ";
	}
	return 0;
}