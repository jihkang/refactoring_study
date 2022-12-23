#include "contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

void	Contact::setFirstName(std::string value)
{
	firstname = value;	
}
void	Contact::setLastName(std::string value)
{
	lastname = value;
}
void	Contact::setNickName(std::string value)
{
	nickname = value;
}
void	Contact::setNumber(std::string _number)
{
	number = _number;
}
void	Contact::setSecret(std::string value)
{
	secret = value;
}

std::string Contact::getFirstName(void)
{	
	if (firstname.length() >= 10) {
		firstname = firstname.substr(0, 10);
		firstname[9] = '.';
	}
	return firstname;
}

std::string Contact::getLastName(void) {
	if (lastname.length() >= 10) {
		lastname = lastname.substr(0, 10);
		lastname[9] = '.';
	}
	return lastname;
}

std::string Contact::getNickName(void)
{
	if (nickname.length() >= 10) {
		nickname = nickname.substr(0, 10);
		nickname[9] = '.';
	}
	return nickname;
}

std::string Contact::getNumber(void)
{
	if (number.length() >= 10) {
		number = number.substr(0, 10);
		number[9] = '.';
	}
	return number;
}

std::string Contact::getSecret(void)
{
	return secret;
}