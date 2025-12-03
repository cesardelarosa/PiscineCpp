#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>
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

void testShrubbery() {
	try {
		Bureaucrat gardener("Gardener", 137);
		Bureaucrat student("Student", 140);
		ShrubberyCreationForm shrub("Home");

		std::cout << GREEN << gardener << RESET << std::endl;
		std::cout << GREEN << student << RESET << std::endl;
		std::cout << GREEN << shrub << RESET << std::endl;

		std::cout << "\n[TEST] Executing unsigned form:" << std::endl;
		try {
			shrub.execute(gardener);
			std::cout << RED << "Should not print (Unsigned executed)" << RESET << std::endl;
		} catch (std::exception &e) {
			std::cout << YELLOW << "Exception caught: " << e.what() << RESET << std::endl;
		}

		std::cout << "\n[ACTION] Student signs the form..." << std::endl;
		student.signForm(shrub);

		std::cout << "\n[TEST] Executing with Grade too low (Student grade 140 vs Exec 137):" << std::endl;
		try {
			shrub.execute(student);
			std::cout << RED << "Should not print (Low grade executed)" << RESET << std::endl;
		} catch (std::exception &e) {
			std::cout << YELLOW << "Exception caught: " << e.what() << RESET << std::endl;
		}

		std::cout << "\n[TEST] Successful execution (Gardener grade 137):" << std::endl;
		gardener.executeForm(shrub);
		std::cout << GREEN << "File 'Home_shrubbery' created." << RESET << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << "Unexpected critical exception: " << e.what() << RESET << std::endl;
	}
}

void testRobotomy() {
	try {
		Bureaucrat doctor("Dr. House", 45);
		RobotomyRequestForm robo("Bender");

		std::cout << GREEN << doctor << RESET << std::endl;
		std::cout << GREEN << robo << RESET << std::endl;

		std::cout << "\n[TEST] Executing unsigned form:" << std::endl;
		try {
			robo.execute(doctor);
			std::cout << RED << "Should not print (Unsigned executed)" << RESET << std::endl;
		} catch (std::exception &e) {
			std::cout << YELLOW << "Exception caught: " << e.what() << RESET << std::endl;
		}

		std::cout << "\n[ACTION] Doctor signs the form..." << std::endl;
		doctor.signForm(robo);

		std::cout << "\n[TEST] Executing 4 times to check randomness (50% chance):" << std::endl;
		for (int i = 0; i < 4; i++) {
			std::cout << "Attempt " << i + 1 << ": ";
			doctor.executeForm(robo);
			std::cout << std::endl;
		}
	} catch (std::exception &e) {
		std::cerr << RED << "Unexpected critical exception: " << e.what() << RESET << std::endl;
	}
}

void testPresidential() {
	try {
		Bureaucrat president("Zaphod", 5);
		Bureaucrat assistant("Assistant", 20);
		PresidentialPardonForm pardon("Arthur Dent");

		std::cout << GREEN << president << RESET << std::endl;
		std::cout << GREEN << assistant << RESET << std::endl;
		std::cout << GREEN << pardon << RESET << std::endl;

		std::cout << "\n[TEST] Executing unsigned form:" << std::endl;
		try {
			pardon.execute(president);
			std::cout << RED << "Should not print (Unsigned executed)" << RESET << std::endl;
		} catch (std::exception &e) {
			std::cout << YELLOW << "Exception caught: " << e.what() << RESET << std::endl;
		}

		std::cout << "\n[ACTION] Assistant signs the form..." << std::endl;
		assistant.signForm(pardon);

		std::cout << "\n[TEST] Executing with Grade too low (Assistant grade 20 vs Exec 5):" << std::endl;
		try {
			pardon.execute(assistant);
			std::cout << RED << "Should not print (Low grade executed)" << RESET << std::endl;
		} catch (std::exception &e) {
			std::cout << YELLOW << "Exception caught: " << e.what() << RESET << std::endl;
		}

		std::cout << "\n[TEST] Successful execution (President grade 5):" << std::endl;
		president.executeForm(pardon);
	} catch (std::exception &e) {
		std::cerr << RED << "Unexpected critical exception: " << e.what() << RESET << std::endl;
	}
}

int main() {
	std::srand(std::time(NULL));

	testGuard("SHRUBBERY CREATION FORM", testShrubbery);
	testGuard("ROBOTOMY REQUEST FORM", testRobotomy);
	testGuard("PRESIDENTIAL PARDON FORM", testPresidential);

	return (0);
}
