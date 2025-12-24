#include "Span.hpp"
#include <iostream>
#include <list>
#include <vector>

void subject_test() {
	std::cout << "--- Subject Test ---" << std::endl;
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void exception_test() {
	std::cout << "\n--- Exception Test ---" << std::endl;
	Span sp = Span(1);

	try {
		sp.addNumber(42);
		sp.addNumber(43);
	} catch (const std::exception &e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	try {
		sp.shortestSpan();
	} catch (const std::exception &e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}
}

void range_test() {
	std::cout << "\n--- Range Test ---" << std::endl;
	Span sp = Span(10000);
	std::vector<int> v;

	for (int i = 0; i < 10000; ++i) {
		v.push_back(i * 2);
	}

	try {
		sp.addNumbers(v.begin(), v.end());
		std::cout << "Size: " << v.size() << std::endl;
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

int main() {
	subject_test();
	exception_test();
	range_test();

	return 0;
}
