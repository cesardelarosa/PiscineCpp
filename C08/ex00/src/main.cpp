#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

void test_vector() {
	int arr[] = {1, 2, 3, 4, 5};
	std::vector<int> v(arr, arr + sizeof(arr) / sizeof(int));

	try {
		std::vector<int>::iterator it = easyfind(v, 3);
		std::cout << "Vector: Found " << *it << std::endl;
		easyfind(v, 42);
	} catch (const std::exception &e) {
		std::cerr << "Vector Error: " << e.what() << std::endl;
	}
}

void test_list() {
	std::list<int> l;
	l.push_back(10);
	l.push_back(20);

	try {
		std::list<int>::iterator it = easyfind(l, 20);
		std::cout << "List: Found " << *it << std::endl;
		easyfind(l, -1);
	} catch (const std::exception &e) {
		std::cerr << "List Error: " << e.what() << std::endl;
	}
}

int main() {
	test_vector();
	std::cout << std::endl;
	test_list();
	return 0;
}
