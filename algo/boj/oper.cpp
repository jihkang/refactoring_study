#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

vector<vector<int> > v = {{10,2}, {1,3}, {2,4}, {9,8}, {7,7}, {9,1}};

bool cmp(vector<int>& begin, vector<int>& end)
{
    if (begin[1] < end[1])
    	return (true);
	if (begin[1] == end[1])
    {
        if (begin[0] > end[0])
            return (true);
       	return (false);
	}
    return (false);
}
    
vector<long long> solution(vector<vector<int> > program) {
    vector<long long> answer(11);
	
    sort(program.begin(), program.end(), cmp);
	for(int i = 0; i < program.size(); ++i) {
		cout<< program[i][0] << " " << program[i][1]<<endl;
	}
    return answer;
}

int	main()
{
	solution(v);
}
