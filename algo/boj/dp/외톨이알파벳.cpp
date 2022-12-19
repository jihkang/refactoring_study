#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string input_string) {
    string answer = "";
    char        buf[128] = {0, };
    int len = input_string.length();

    for (int i = 0; i < len; ++i) {
		++buf[input_string[i]];
		if (buf[input_string[i]] == 2) {
			if (input_string[i] == input_string[i - 1])
				--buf[input_string[i]];
			else
				answer += input_string[i];
		}
    }
	if (answer == "")
		answer += "N";
	else
		sort(answer.begin(), answer.end());
    return answer;
}

int	main()
{
	string input = "zbzbz";
	cout<<solution(input);
}
