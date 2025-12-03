#include "ScalarConverter.hpp"
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &src) { (void)src; }

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs) {
	(void)rhs;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string const &literal) {
	double d = 0.0;
	char *endPtr = NULL;

	if (literal.length() == 1 && !std::isdigit(literal[0]) &&
		std::isprint(literal[0])) {
		d = static_cast<double>(literal[0]);
	} else {
		d = std::strtod(literal.c_str(), &endPtr);
		if (literal.empty() ||
			(*endPtr != '\0' && !(*endPtr == 'f' && *(endPtr + 1) == '\0'))) {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
	}

	bool isNan = std::isnan(d);
	bool isInf = std::isinf(d);
	bool isIntPossible = !isNan && !isInf &&
						 d >= std::numeric_limits<int>::min() &&
						 d <= std::numeric_limits<int>::max();
	bool isCharPossible = !isNan && !isInf && d >= 0 && d <= 127;

	std::cout << "char: ";
	if (!isCharPossible)
		std::cout << "impossible";
	else if (!std::isprint(static_cast<char>(d)))
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(d) << "'";
	std::cout << std::endl;

	std::cout << "int: ";
	if (!isIntPossible)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(d);
	std::cout << std::endl;

	if (!isInf && d == std::floor(d)) {
		std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	} else {
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}
