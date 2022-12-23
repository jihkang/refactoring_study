#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string.h>
#include <iostream>

class Contact {
public:
	Contact();
	~Contact();
	void	setFirstName(std::string value);
	void	setLastName(std::string value);
	void	setNickName(std::string value);
	void	setNumber(std::string number);
	void	setSecret(std::string value);
	std::string getFirstName(void);
	std::string getLastName(void);
	std::string getNickName(void);
	std::string getNumber(void);
	std::string getSecret(void);
private:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string number;
	std::string secret;
};

#endif