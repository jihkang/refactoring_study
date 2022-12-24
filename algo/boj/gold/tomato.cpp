#include <iostream>
#include <queue>

using namespace std;

int	tomato[1000][1000];
int cnt = -1;
int n, m;

int mx[] = {0, 0, 1, -1};
int my[] = {-1, 1, 0, 0};

void solve(queue<vector<int>>& v)
{
	if (v.size() == 0) 
	{
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (tomato[i][j] == 0)
				{
					cout << "-1"<<endl;
					return ;
				}
			}
		} 
		cout << cnt << endl;
		return ;
	}
	int len = v.size();
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < 4; ++j) {
			vector<int> vp;
			vp = v.front();
			int _x = vp[0] + mx[j];
			int _y = vp[1] + my[j];
			if (_x >= 0 && _x < m && _y >= 0 && _y < n)
			{
				if (tomato[_x][_y] == 0) {
					tomato[_x][_y] = 1;
					vector<int> p;
					p.push_back(_x);
					p.push_back(_y);
					v.push(p);
				}
			}
		}
		v.pop();
	}
	cnt++;
	solve(v);
}

int main()
{

	cin >> n >> m;
	queue<vector<int>> v;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin>>tomato[i][j];
			vector<int> p;
			if (tomato[i][j] == 1) {
				p.push_back(i);
				p.push_back(j);
				v.push(p);
			}
		}
	}
	solve(v);
	return 0;
}