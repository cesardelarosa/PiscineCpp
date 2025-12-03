#include "Bureaucrat.hpp"
#include "Form.hpp"
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

void testFormConstruction() {
	try {
		std::cout << "Creating a standard Form..." << std::endl;
		Form form("Tax Return", 50, 100);
		std::cout << GREEN << form << RESET << std::endl;

		std::cout << "Creating a copy..." << std::endl;
		Form copy(form);
		std::cout << GREEN << copy << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << "Unexpected Exception: " << e.what() << RESET << std::endl;
	}
}

void testInvalidFormHigh() {
	try {
		std::cout << "Attempting to create Form with grade 0..." << std::endl;
		Form bad("TooHigh", 0, 50);
		std::cout << RED << "Should not print (Constructor failed to throw)" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << YELLOW << "Exception caught: " << e.what() << RESET << std::endl;
	}
}

void testInvalidFormLow() {
	try {
		std::cout << "Attempting to create Form with grade 151..." << std::endl;
		Form bad("TooLow", 151, 50);
		std::cout << RED << "Should not print (Constructor failed to throw)" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << YELLOW << "Exception caught: " << e.what() << RESET << std::endl;
	}
}

void testSignSuccess() {
	try {
		Bureaucrat alice("Alice", 10);
		Form contract("Contract", 20, 20);

		std::cout << GREEN << alice << RESET << std::endl;
		std::cout << GREEN << contract << RESET << std::endl;

		std::cout << "Alice signs the contract..." << std::endl;
		alice.signForm(contract);

		std::cout << GREEN << contract << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << "Unexpected Exception: " << e.what() << RESET << std::endl;
	}
}

void testSignFailure() {
	try {
		Bureaucrat bob("Bob", 100);
		Form topSecret("Top Secret", 1, 1);

		std::cout << GREEN << bob << RESET << std::endl;
		std::cout << GREEN << topSecret << RESET << std::endl;

		std::cout << "Bob tries to sign (via signForm)..." << std::endl;
		bob.signForm(topSecret);

		std::cout << "Manually forcing beSigned to catch exception type:" << std::endl;
		topSecret.beSigned(bob);
		std::cout << RED << "Should not print (beSigned failed to throw)" << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << YELLOW << "Exception caught: " << e.what() << RESET << std::endl;
	}
}

int main() {
	testGuard("FORM CONSTRUCTION", testFormConstruction);
	testGuard("INVALID HIGH GRADE", testInvalidFormHigh);
	testGuard("INVALID LOW GRADE", testInvalidFormLow);
	testGuard("SIGNING SUCCESS", testSignSuccess);
	testGuard("SIGNING FAILURE", testSignFailure);
	return (0);
}
