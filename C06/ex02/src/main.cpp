#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define BOLD "\033[1m"

Base *generate(void) {
	int i = std::rand() % 3;
	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;
	else
		return new C;
}

void identify(Base *p) {
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base &p) {
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception &e) {
		try {
			(void)dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
		} catch (std::exception &e) {
			try {
				(void)dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
			} catch (std::exception &e) {
				std::cout << "Unknown" << std::endl;
			}
		}
	}
}

int main() {
	std::srand(std::time(NULL));

	std::cout << BOLD << BLUE << "\n=== IDENTITY THEFT TEST ===" << RESET
			  << std::endl;

	for (int i = 0; i < 12; i++) {
		std::cout << YELLOW << "\nTest " << i + 1 << ":" << RESET << std::endl;

		Base *ptr = generate();
		std::cout << "Generated object at: " << ptr << std::endl;

		std::cout << "Identify via Pointer:   " << GREEN;
		identify(ptr);
		std::cout << RESET;

		std::cout << "Identify via Reference: " << GREEN;
		identify(*ptr);
		std::cout << RESET;

		delete ptr;
	}

	std::cout << BOLD << BLUE << "\n=== END OF TEST ===" << RESET << std::endl;
	return 0;
}
