#include <iostream>

using namespace std;

int		n, m;
char	map[51][51];
int		minCnt = 64;

char wb[][9] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
};

char bw[][9] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
};

void	solve() {
	int count;

	for(int i = 0; i < n; ++i) {
		if (i + 8 > n)
			continue ;
		for(int j = 0; j < m; ++j) {
			int cnt = 0, cnt2 = 0;
			if (j + 8 > m)
				continue ;
			for (int k = 0; k < 8; k++) {
				for (int l = 0; l < 8; l++) {
					if (map[i + k][j + l] != wb[k][l])
						cnt++;
					if (map[i + k][j + l] != bw[k][l])
						cnt2++;
				}
			}
			cnt = cnt2 < cnt ? cnt2 : cnt;
			if (minCnt > cnt) 
			{
				minCnt = cnt;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> map[i][j];
		}
	}
	solve();
	cout << minCnt;
	return 0;
}