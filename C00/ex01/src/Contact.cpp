#include "Contact.hpp"
#include <iomanip>
#include <iostream>

Contact::Contact() {}
Contact::~Contact() {}

static std::string formatField(const std::string &s) {
	if (s.length() > 10) {
		return s.substr(0, 9) + ".";
	}
	return s;
}

std::string Contact::_prompt(const std::string &prompt) {
	std::string input;

	do {
		std::cout << prompt;
		std::getline(std::cin, input);
	} while (input.empty());

	return input;
}

void Contact::fillFromPrompt() {
	_firstName = _prompt("First Name: ");
	_lastName = _prompt("Last Name: ");
	_nickName = _prompt("Nickname: ");
	_phoneNumber = _prompt("Phone Number: ");
	_darkestSecret = _prompt("Darkest Secret: ");

	std::cout << std::endl;
}

void Contact::printCard() const {
	std::cout << "First Name: " << _firstName << std::endl;
	std::cout << "Last Name: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickName << std::endl;
	std::cout << "Phone Number: " << _phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
}

void Contact::printRow(size_t index) const {
	std::cout << std::setw(10) << std::right << index << "|";
	std::cout << std::setw(10) << std::right << formatField(_firstName) << "|";
	std::cout << std::setw(10) << std::right << formatField(_lastName) << "|";
	std::cout << std::setw(10) << std::right << formatField(_nickName)
			  << std::endl;
}
