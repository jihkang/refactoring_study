#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();
	void	routine();
private:
	void	add();
	void	search();
	void	exit();
	void	totalDisplay();
	void	display(int num);

private:
	bool	valid;
	int		mSaved;
	int		mInd;
	Contact mConcat[8];
};

#endif