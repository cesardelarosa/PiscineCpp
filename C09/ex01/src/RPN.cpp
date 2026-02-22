#include "RPN.hpp"
#include <iostream>
#include <ostream>
#include <stdexcept>

// Orthodox Canonical Form

RPN::RPN() {}

RPN::RPN(const RPN &src) { *this = src; }

RPN &RPN::operator=(const RPN &rhs) {
	if (this != &rhs) {
		this->_stack = rhs._stack;
	}
	return *this;
}

RPN::~RPN() {}

// Public Method

void RPN::calculate(const std::string &expression) {
	for (size_t i = 0; i < expression.size(); i++) {
		char c = expression[i];

		if (c == ' ') {
			continue;
		}

		if (isdigit(c)) {
			_stack.push(c - '0');
		} else if (isOperator(c)) {
			performOperation(c);
		} else {
			throw std::invalid_argument("Invalid character in expression");
		}
	}

	if (_stack.size() != 1) {
		throw std::invalid_argument("Too many operands in expression");
	}

	std::cout << _stack.top() << std::endl;
}

// Private Helpers

bool RPN::isOperator(char c) const {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

void RPN::performOperation(char op) {
	int n1, n2;

	if (_stack.size() < 2) {
		throw std::out_of_range("Stack underflow");
	}
	n1 = _stack.top();
	_stack.pop();
	n2 = _stack.top();
	_stack.pop();

	switch (op) {
	case '+':
		_stack.push(n2 + n1);
		break;
	case '-':
		_stack.push(n2 - n1);
		break;
	case '*':
		_stack.push(n2 * n1);
		break;
	case '/':
		if (n1 == 0) {
			throw std::runtime_error("Division by zero");
		}
		_stack.push(n2 / n1);
		break;
	}
}
