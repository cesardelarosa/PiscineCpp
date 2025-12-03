#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
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

void testValidCreation() {
	Intern someRandomIntern;
	AForm *form;

	std::cout << "--- Robotomy Request ---" << std::endl;
	form = someRandomIntern.makeForm("robotomy request", "Bender");
	if (form) {
		std::cout << GREEN << *form << RESET << std::endl;
		delete form;
	} else
		std::cout << RED << "Should not print (Form is NULL)" << RESET << std::endl;

	std::cout << "\n--- Presidential Pardon ---" << std::endl;
	form = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
	if (form) {
		std::cout << GREEN << *form << RESET << std::endl;
		delete form;
	} else
		std::cout << RED << "Should not print (Form is NULL)" << RESET << std::endl;

	std::cout << "\n--- Shrubbery Creation ---" << std::endl;
	form = someRandomIntern.makeForm("shrubbery creation", "Garden");
	if (form) {
		std::cout << GREEN << *form << RESET << std::endl;
		delete form;
	} else
		std::cout << RED << "Should not print (Form is NULL)" << RESET << std::endl;
}

void testInvalidCreation() {
	Intern someRandomIntern;
	AForm *form;

	std::cout << "--- Non-existent Form ---" << std::endl;
	form = someRandomIntern.makeForm("tax return", "Nobody");

	if (form == NULL)
		std::cout << GREEN << "Success! Intern did not create unknown form." << RESET << std::endl;
	else {
		std::cout << RED << "Should not print (Unknown form was created)" << RESET << std::endl;
		delete form;
	}
}

void testInternLifecycle() {
	Intern maker;
	Bureaucrat boss("Boss", 1);
	AForm *form;

	std::cout << GREEN << boss << RESET << std::endl;

	std::cout << "\n[STEP 1] Intern creates form..." << std::endl;
	form = maker.makeForm("presidential pardon", "Criminal");

	if (form) {
		std::cout << GREEN << *form << RESET << std::endl;

		std::cout << "\n[STEP 2] Boss signs form..." << std::endl;
		boss.signForm(*form);
		std::cout << GREEN << *form << RESET << std::endl;

		std::cout << "\n[STEP 3] Boss executes form..." << std::endl;
		boss.executeForm(*form);

		delete form;
	} else
		std::cout << RED << "Should not print (Lifecycle failed at creation)" << RESET << std::endl;
}

int main() {
	testGuard("VALID FORM CREATION", testValidCreation);
	testGuard("INVALID FORM CREATION", testInvalidCreation);
	testGuard("FULL LIFECYCLE TEST", testInternLifecycle);

	return (0);
}
