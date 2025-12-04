#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T> void print(const T &x) { std::cout << x << std::endl; }

void increment(int &n) { n++; }

void toUpper(std::string &s) {
	for (size_t i = 0; i < s.length(); i++) {
		s[i] = std::toupper(s[i]);
	}
}

int main(void) {
	std::cout << "--- TEST 1: Int Array & Modification ---" << std::endl;
	int arrayInt[] = {0, 1, 2, 3, 4};
	size_t lenInt = 5;

	std::cout << "Original:" << std::endl;
	::iter(arrayInt, lenInt, print<int>);

	std::cout << "Incrementing..." << std::endl;
	::iter(arrayInt, lenInt, increment);

	std::cout << "Modified:" << std::endl;
	::iter(arrayInt, lenInt, print<int>);

	std::cout << std::endl;

	std::cout << "--- TEST 2: String Array ---" << std::endl;
	std::string arrayStr[] = {"hola", "mundo", "42", "madrid"};
	size_t lenStr = 4;

	std::cout << "Original:" << std::endl;
	::iter(arrayStr, lenStr, print<std::string>);

	::iter(arrayStr, lenStr, toUpper);

	std::cout << "Modified (Upper):" << std::endl;
	::iter(arrayStr, lenStr, print<std::string>);

	std::cout << std::endl;

	std::cout << "--- TEST 3: Const Array ---" << std::endl;
	const int constArray[] = {100, 200, 300};

	::iter(constArray, 3, print<const int>);

	return 0;
}
