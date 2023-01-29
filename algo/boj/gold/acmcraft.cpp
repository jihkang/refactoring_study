#include <iostream>
#include <deque>
#include <vector>
#include <utility>
#include <memset>

using namespace std;

int		dp[1001];
int		arr[1001];
int		check[1001];
bool	visited[1001];
vector<int> graph[1001];
int		n, m, k;


void	solve(deque<int>& q)
{
	for (int i = 0; i < n; ++i) {
		int cur = q.front();
		q.pop_front();
		for (int j = 0; j < graph[cur].size(); j++) {
			int next = graph[cur][j];
			dp[next] = max(dp[next], dp[cur] + arr[next]);
			if (--check[next] == 0) {
				q.push_back(next);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int	t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		deque<int> q;
		for (int i = 1; i <= n; ++i) {
			cin >> arr[i];
			dp[i] = arr[i];
		}
		int start = 1;
		for (int i = 0; i < m; ++i) {
			int x, y;
			cin >> x >> y;
			graph[x].emplace_back(y);
			check[y]++;
		}
		for (int i = 1; i <= n; ++i) {
			if (check[i] == 0) {
				q.push_back(i);
				break;
			}
		}
		cin >> k;
		solve(q);
		cout << dp[k] << "\n";	
	}
	return 0;
}