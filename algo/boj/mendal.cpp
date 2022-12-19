#include <iostream>
#include <vector>
#include <string>

using namespace std;

void	mendalGene(int par, int chd, string& gene)
{
	if (par == 1)
	{
		gene = "Rr";
		return ;
	}
	else if (gene == "")
		mendalGene(par - 1, chd / 4, gene);
	if (gene == "Rr")
	{
		switch (chd % 4) {
			case 0:
				gene = "RR";
				break;
			case 1:
				gene = "Rr";
			case 2:
				gene = "Rr";
				break;
			case 3:
				gene = "rr";
				break;
		}
	}
}

vector<string> solution(vector<vector<int> > queries)
{
	vector<string> ans;
	for(int i = 0; i < queries.size(); ++i) {
		int	parent = queries[i][0];
		int	child = queries[i][1];
		string str = "";
		mendalGene(parent, child - 1, str);
		ans.push_back(str);
	}
	return ans; 
}

int main()
{
	vector<vector<int> > v;
	vector<int> v2;
	vector<int> v3;
	v2.push_back(3);
	v2.push_back(1);
	v3.push_back(3);
	v3.push_back(9);
	v.push_back(v2);
	v.push_back(v3);
	solution(v);
}
