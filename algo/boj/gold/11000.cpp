#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Heap {
public:
	Heap() : len(0) {}
	void add(int s, int e);
	void pop();
	int top();
	void childSwap();
	void parentSwap();
public :
	vector<int> v;
	int			len;
};

void Heap::add(int s, int e) {
	if (len >= 1 && this->top() <= s) {
		this->childSwap();
	}
	v.push_back(e);
	++len;
	this->parentSwap();
}

int Heap::top() {
	if (len == 0)
		return (-1);
	return (this->v[0]);
}

void Heap::pop() {
	v.pop_back();
	--len;
}

void Heap::parentSwap() {
	int i;
	int s = len - 1;
	i = (s - 1) / 2;
	for (; i >= 0; i = (i - 1) / 2) {
		if (v[i] > v[s]) 
			swap(v[i], v[s]);
		if (i == 0)
			break ;
		s = i;
	}
}

void Heap::childSwap() {
	if (len < 1)
		return ;
	v[0] = v[len - 1];
	this->pop();
	int i, s;
	s = 0;
	for (i = 1; i < len;) {
		if (i + 1 < len && v[i + 1] < v[i])
			++i;
		if (v[i] < v[s])
			swap(v[i], v[s]);
		else
			break;
		s = i;
		i = i * 2 + 1;
	}		
}

int main()
{
	Heap root;
	int n;
	vector<vector<int>> v;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		vector<int> p(2);
		cin>>p[0] >> p[1];
		v.push_back(p);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; ++i) {
		root.add(v[i][0], v[i][1]);
	}
	cout << root.len << endl;
	return 0;
}