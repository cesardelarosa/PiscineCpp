#include "Array.hpp"
#include <iostream>
#include <string>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define BOLD "\033[1m"

void testGuard(std::string title, void (*testFunc)()) {
	std::cout << BOLD << BLUE << "\n=== " << title << " ===" << RESET
			  << std::endl;
	testFunc();
	std::cout << "----------------------------------------" << std::endl;
}

void testSimpleTypes() {
	std::cout << "Creating Array<int> of size 5..." << std::endl;
	Array<int> numbers(5);

	std::cout << "Size: " << numbers.size() << std::endl;

	std::cout << "Filling array..." << std::endl;
	for (unsigned int i = 0; i < numbers.size(); i++) {
		numbers[i] = i * 10;
	}

	std::cout << "Reading array: ";
	for (unsigned int i = 0; i < numbers.size(); i++) {
		std::cout << numbers[i] << " ";
	}
	std::cout << GREEN << "[OK]" << RESET << std::endl;
}

void testComplexTypes() {
	std::cout << "Creating Array<std::string>..." << std::endl;
	Array<std::string> strings(3);

	strings[0] = "Hola";
	strings[1] = "Mundo";
	strings[2] = "42";

	std::cout << "Content: ";
	for (unsigned int i = 0; i < strings.size(); i++) {
		std::cout << "'" << strings[i] << "' ";
	}
	std::cout << GREEN << "[OK]" << RESET << std::endl;
}

void testDeepCopy() {
	std::cout << "Creating original array..." << std::endl;
	Array<int> original(3);
	original[0] = 100;

	std::cout << "Creating copy (assignment operator)..." << std::endl;
	Array<int> copy = original;

	std::cout << "Modifying copy[0] to 999..." << std::endl;
	copy[0] = 999;

	std::cout << "Original[0]: " << original[0] << std::endl;
	std::cout << "Copy[0]:     " << copy[0] << std::endl;

	if (original[0] != copy[0])
		std::cout << GREEN << "SUCCESS: Original remains unchanged." << RESET
				  << std::endl;
	else
		std::cout << RED << "FAILURE: Original was modified!" << RESET
				  << std::endl;
}

void testExceptions() {
	Array<int> arr(5);

	std::cout << "Attempting valid access..." << std::endl;
	try {
		arr[4] = 42;
		std::cout << GREEN << "Valid access OK." << RESET << std::endl;
	} catch (const std::exception &e) {
		std::cout << RED << "Unexpected error: " << e.what() << RESET
				  << std::endl;
	}

	std::cout << "Attempting index too high (index 10)..." << std::endl;
	try {
		arr[10] = 42;
		std::cout << RED << "Should not print (Exception expected)" << RESET
				  << std::endl;
	} catch (const std::exception &e) {
		std::cout << YELLOW << "Caught expected exception: " << e.what()
				  << RESET << std::endl;
	}

	std::cout << "Attempting negative index (-1)..." << std::endl;
	try {
		arr[-1] = 42;
		std::cout << RED << "Should not print (Exception expected)" << RESET
				  << std::endl;
	} catch (const std::exception &e) {
		std::cout << YELLOW << "Caught expected exception: " << e.what()
				  << RESET << std::endl;
	}
}

void testEmptyArray() {
	std::cout << "Creating empty array..." << std::endl;
	Array<int> empty;

	std::cout << "Size: " << empty.size() << std::endl;

	try {
		std::cout << "Accessing index 0..." << std::endl;
		empty[0] = 1;
		std::cout << RED << "Should not print (Exception expected)" << RESET
				  << std::endl;
	} catch (const std::exception &e) {
		std::cout << YELLOW << "Caught exception on empty array access" << RESET
				  << std::endl;
	}
}

int main() {
	testGuard("SIMPLE TYPES (INT)", testSimpleTypes);
	testGuard("COMPLEX TYPES (STRING)", testComplexTypes);
	testGuard("DEEP COPY CHECK", testDeepCopy);
	testGuard("EXCEPTION HANDLING", testExceptions);
	testGuard("EMPTY ARRAY EDGE CASE", testEmptyArray);

	return 0;
}
