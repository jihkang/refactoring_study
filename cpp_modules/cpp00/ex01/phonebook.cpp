#include "phonebook.hpp"
#include "utils.hpp"
#include <iostream>
#include <iomanip>
#include <stdlib.h>

PhoneBook::PhoneBook() {
	mInd = 0;
	mSaved = 0;
}

PhoneBook::~PhoneBook() { }

void PhoneBook::routine() {
	bool	svalid = false;
	while (!svalid)
	{
		std::string cmd;
		std::cout << "input cmd : ";
		stringCin(cmd, svalid);
		if (cmd == "EXIT")
			break ;
		else if (cmd == "ADD")
		{
			printf("ADD input\n");
			this->add();
		}
		else if (cmd == "SEARCH")
		{
			printf("SEARCH INPUT\n");
			this->search();	
		}
		else
		{
			if (cmd == "")
				break;
			std::cout << cmd << " "<< "doesn't have" << "\n";
		}
		// system("leaks phonebook");
	}
}

void PhoneBook::add() {
	std::string name;

	mConcat[mInd].setFirstName("");
	mConcat[mInd].setLastName("");
	mConcat[mInd].setNickName("");
	mConcat[mInd].setNumber("");
	mConcat[mInd].setSecret("");
	std::cout<<"input first name : ";
	stringCin(name, this->valid);
	mConcat[mInd].setFirstName(name);
	std::cout<<"input last name : ";
	stringCin(name, this->valid);
	mConcat[mInd].setLastName(name);
	std::cout << "input nick name : ";
	stringCin(name, this->valid);
	mConcat[mInd].setNickName(name);
	std::cout << "input phone number : ";
	stringCin(name, this->valid);
	mConcat[mInd].setNumber(name);
	std::cout << "input your secret : ";
	stringCin(name, this->valid);
	mConcat[mInd].setSecret(name);
	if (this->valid == true)
		return ;
	mInd = mInd != 7 ? mInd + 1: 0;
	if (mSaved != 8)
		++mSaved;
}

void PhoneBook::search() {
	std::string input;
	bool		valid = false;
	int 		num;

	if (this->mSaved == 0)
		return ;	
	totalDisplay();
	std::cout<<"input idx : " << std::endl;
	stringCin(input, valid);
	if (valid == true)
		return ;
	num = atoi(input.c_str());
	if (num > mSaved && num <= 0)
		return ;
	display(num);
}

void PhoneBook::totalDisplay() {
	for (int i = 0; i < mSaved; ++i) {
		std::cout.width(10);
		std::cout.fill(' ');
		std::cout<< i + 1;
		std::cout<< "|";
		std::cout.width(10);
		std::cout.fill(' ');
		std::cout<< mConcat[i].getFirstName();
		std::cout<< "|";
		std::cout.width(10);
		std::cout.fill(' ');
		std::cout<<mConcat[i].getLastName();
		std::cout<< "|";
		std::cout.width(10);
		std::cout.fill(' ');			
		std::cout<<mConcat[i].getNickName();
		std::cout<<std::endl;
	}
}

void PhoneBook::display(int ind) {
	std::cout << mConcat[ind - 1].getFirstName() << "SECRET  : " << mConcat[ind - 1].getSecret() << std::endl;
}
