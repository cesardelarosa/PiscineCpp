#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

void subject_test() {
	std::cout << "--- Subject Test ---" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void reverse_iterator_test() {
	std::cout << "--- Reverse Iterator Test ---" << std::endl;
	MutantStack<int> mstack;

	mstack.push(1);
	mstack.push(2);
	mstack.push(3);

	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();

	while (rit != rite) {
		std::cout << *rit << std::endl;
		++rit;
	}
}

void const_iterator_test() {
	std::cout << "--- Const Iterator Test ---" << std::endl;
	MutantStack<int> mstack;
	mstack.push(42);
	mstack.push(24);

	const MutantStack<int> cstack(mstack);
	MutantStack<int>::const_iterator it = cstack.begin();
	MutantStack<int>::const_iterator ite = cstack.end();

	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
}

void list_comparison_test() {
	std::cout << "--- List Comparison Test ---" << std::endl;
	std::list<int> l;

	l.push_back(5);
	l.push_back(17);
	l.pop_back();
	l.push_back(3);
	l.push_back(5);
	l.push_back(737);
	l.push_back(0);

	std::list<int>::iterator it = l.begin();
	std::list<int>::iterator ite = l.end();

	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
}

int main() {
	subject_test();
	std::cout << std::endl;
	reverse_iterator_test();
	std::cout << std::endl;
	const_iterator_test();
	std::cout << std::endl;
	list_comparison_test();

	return 0;
}
