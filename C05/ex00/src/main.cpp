#include "Bureaucrat.hpp"
#include <iostream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define BOLD "\033[1m"

void testGuard(std::string title, void (*testFunc)()) {
	std::cout << BOLD << BLUE << "\n=== " << title << " ===" << RESET << std::endl;
	testFunc();
	std::cout << "----------------------------------------" << std::endl;
}

void testNormalBureaucrat() {
	try {
		Bureaucrat alice("Alice", 2);

		std::cout << GREEN << alice << RESET << std::endl;
		std::cout << "Incrementing grade..." << std::endl;
		alice.incrementGrade();
		std::cout << GREEN << alice << RESET << std::endl;
		std::cout << "Decrementing grade..." << std::endl;
		alice.decrementGrade();
		std::cout << GREEN << alice << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << "Unexpected Exception: " << e.what() << RESET << std::endl;
	}
}

void testGradeTooHigh() {
	try {
		std::cout << "Attempting to create Bureaucrat with grade 0..." << std::endl;
		Bureaucrat high("TooHigh", 0);
		std::cout << RED << "Should not print (Constructor failed to throw)" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << YELLOW << "Exception caught: " << e.what() << RESET << std::endl;
	}
}

void testGradeTooLow() {
	try {
		std::cout << "Attempting to create Bureaucrat with grade 151..." << std::endl;
		Bureaucrat low("TooLow", 151);
		std::cout << RED << "Should not print (Constructor failed to throw)" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << YELLOW << "Exception caught: " << e.what() << RESET << std::endl;
	}
}

void testIncrementError() {
	try {
		Bureaucrat boss("Boss", 1);

		std::cout << GREEN << boss << RESET << std::endl;
		std::cout << "Attempting to increment grade 1..." << std::endl;
		boss.incrementGrade();
		std::cout << RED << "Should not print (Increment failed to throw)" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << YELLOW << "Exception caught: " << e.what() << RESET << std::endl;
	}
}

void testDecrementError() {
	try {
		Bureaucrat intern("Intern", 150);

		std::cout << GREEN << intern << RESET << std::endl;
		std::cout << "Attempting to decrement grade 150..." << std::endl;
		intern.decrementGrade();
		std::cout << RED << "Should not print (Decrement failed to throw)" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << YELLOW << "Exception caught: " << e.what() << RESET << std::endl;
	}
}

int main() {
	testGuard("STANDARD USAGE", testNormalBureaucrat);
	testGuard("CONSTRUCTOR TOO HIGH", testGradeTooHigh);
	testGuard("CONSTRUCTOR TOO LOW", testGradeTooLow);
	testGuard("INCREMENT LIMIT", testIncrementError);
	testGuard("DECREMENT LIMIT", testDecrementError);
	return (0);
}
