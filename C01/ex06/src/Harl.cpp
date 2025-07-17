#include "Harl.hpp"
#include <iostream>
#include <string>

void Harl::debug() {
	std::cout
		<< "[DEBUG] "
		<< "I love having extra bacon for my "
		   "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
		<< std::endl;
}

void Harl::info() {
	std::cout
		<< "[INFO] "
		<< "I cannot believe adding extra bacon costs more money. You didn’t put "
		   "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
		<< std::endl;
}

void Harl::warning() {
	std::cout
		<< "[WARNING] "
		<< "I think I deserve to have some extra bacon for free. I’ve been "
		   "coming for years, whereas you started working here just last month."
		<< std::endl;
}

void Harl::error() {
	std::cout << "[ERROR] "
			  << "This is unacceptable! I want to speak to the manager now."
			  << std::endl;
}

int getLevelIndex(const std::string &level) {
	if (level == "DEBUG")
		return 0;
	if (level == "INFO")
		return 1;
	if (level == "WARNING")
		return 2;
	if (level == "ERROR")
		return 3;
	return -1;
}

void Harl::complain(std::string level) {
	switch (getLevelIndex(level)) {
	case 0:
		debug();
		/* fallthrough */
	case 1:
		info();
		/* fallthrough */
	case 2:
		warning();
		/* fallthrough */
	case 3:
		error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]"
				  << std::endl;
		break;
	}
}

Harl::Harl() {}

Harl::~Harl() {}
