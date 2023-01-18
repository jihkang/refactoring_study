#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, s;
int last;

int num[1001][1001];
int dp[1001];

void dfs(int s)
{
	cout << s << " ";
	dp[s] = 1;
	for (int i = 0; i < n; ++i) {
		if (dp[i + 1] == 1 || num[s][i + 1] == 0) {
			continue ;	
		}
		dfs(i + 1);
	}
}

void bfs(std::queue<int>& que)
{
	if (que.empty())
		return ;
	int value;
	value = que.front();
	cout << value << " ";
	que.pop();
	for (int i = 0; i < n; ++i) {
		if (dp[i + 1] == 0 || num[value][i + 1] == 0) {
			continue ;
		}
		que.push(i + 1);
		dp[i + 1] = 0;
	}
	bfs(que);
}

int main()
{
	std::queue<int> q;
	cin >> n >> m >> s;
	for (int i = 0 ; i < m; ++i) {
		int x, y;
		cin >>x >> y; 
		num[x][y] = num[y][x] = 1;
	}
	dfs(s);
	cout << "\n";
	q.push(s);
	dp[s] = 0;
	bfs(q);
	return 0;
}