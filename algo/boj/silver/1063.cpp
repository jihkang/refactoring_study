#include <iostream>

using namespace std;

int k[2];
int s[2];
int _x[] = {0, 0, -1, 1, 1, 1, -1, -1};
int _y[] = {1, -1, 0, 0, 1, -1, 1, -1};

int switchMv(string str)
{
	if (str == "R") {
		return (0);
	} else if (str == "L") {
		return (1);
	} else if (str == "B") {
		return (2);	
	}else if (str == "T") {
		return (3);	
	}else if (str == "RT") {
		return (4);	
	}else if (str == "LT") {
		return (5);	
	}else if (str == "RB") {
		return (6);	
	} else if (str == "LB") {
		return (7);	
	}
	return (-1);
}

int main()
{
	char c;
	int n;

	cin >> c >> n;
	k[1] = c - 'A';
	k[0] = n - 1;
	cin >> c >> n;
	s[1] = c - 'A';
	s[0] = n - 1;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string mv;
		cin >> mv;
		int x, y, sx, sy;
		int cnt = switchMv(mv); 
		x = k[1] + _y[cnt];
		y = k[0] + _x[cnt]; 
		sx = s[1] + _y[cnt]; 
		sy = s[0] + _x[cnt];
		cout << (char)(x + 'A') << y + 1 << endl;
		cout << (char)(s[1] + 'A') << s[0] + 1 << endl;
		if (x < 0 || x >= 8 || y < 0 || y >= 8)
			continue ;
		if (x == s[1] && y == s[0]){
			if (sx < 0 || sx >= 8 || sy < 0 || sy >= 8)
				continue ;
			s[1] = sx;
			s[0] = sy;
		}
		k[1] = x;
		k[0] = y;

	}
	cout << (char)(k[1] + 'A') << k[0] + 1 << endl;
	cout << (char)(s[1] + 'A') << s[0] + 1 << endl;
	return 0;
}