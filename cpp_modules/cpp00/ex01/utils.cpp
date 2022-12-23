#include "utils.hpp"
#include <iostream>

void stringCin(std::string& str, bool& valid){
	if (valid)
		return ;
	std::cin>>str;
	if (std::cin.eof())
	{
		str = "";
		valid = true;
	}
	valid = false;
}