#include <iostream>
#include <deque>
#include <cstring>

int dp[10001];
char	ch[] = {'D', 'S', 'L', 'R'};
using namespace std;

int	double_value(int start)
{
	return (start * 2) % 10000;
}

int	s_value(int start)
{
	if (start == 0)
		return 9999;
	return start - 1;
}

int	left_rotate(int start)
{
	return (start * 10) % 10000 + (start / 1000);
}

int right_rotate(int start)
{
	return (start / 10) + (start % 10) * 1000;
}

int	run_cmd(int start, int idx) {
	if (idx == 0)
		return double_value(start);
	else if (idx == 1)
		return s_value(start);
	else if (idx == 2)
		return left_rotate(start);
	else
		return right_rotate(start);
}

void	solve_correct(int end, int cnt, deque<string>& str, deque<int>& dq)
{
	if (dq.empty())
		return ;
	int	len = dq.size();
	for (int i = 0; i < len; ++i) {
		int	start = dq[0];
		string cur = str[0];
		if (start == end)
		{
			std::cout << cur << "\n";
			return ;
		}
		for (int j = 0; j < 4; ++j) {
			string p = cur + ch[j];
			int t = run_cmd(start, j);
			// cout << p << t << "\n";
			if (dp[t] == -1) {
				str.push_back(p);
				dq.push_back(run_cmd(start, j));
				dp[t] = cnt + 1;
			}
		}
		str.pop_front();
		dq.pop_front();
	}
	solve_correct(end, cnt + 1, str, dq);
}

void	solve(int start, int end)
{
	for (int i = 0; i < 10000; ++i) {
		dp[i] = -1;	
	}
	deque<string> str;
	deque<int> dq;
	dq.push_back(start);
	dp[start] = 0;
	str.push_back("");
	solve_correct(end, 0, str, dq);
}

int main()
{
	int start, end;
	int	n;

	cin >> n;
 
	for (int i = 0; i < n; ++i)
	{
		cin >> start >> end;
		solve(start, end);
	}
	return 0;
}