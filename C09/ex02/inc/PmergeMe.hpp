#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

class PmergeMe {
  public:
	PmergeMe();
	PmergeMe(const PmergeMe &src);
	PmergeMe &operator=(const PmergeMe &rhs);
	~PmergeMe();

	void process(int argc, char **argv);

  private:
	std::deque<int> _deque;
	std::vector<int> _vector;

	static const int n_print = 10;

	void printBefore(int argc, char **argv) const;
	
	template <typename Container> 
	void printAfter(const Container &c) const;

	void parseData(std::vector<int> &c, int argc, char **argv);
	void parseData(std::deque<int> &c, int argc, char **argv);

	std::vector<int> getInsertionOrder(int n_pairs);

	void fordJohnsonSort(std::vector<int> &vec);
	void fordJohnsonSort(std::deque<int> &deq);

	void fordJohnsonRecursive(std::vector<int> &vec, size_t stride);
	void fordJohnsonRecursive(std::deque<int> &deq, size_t stride);
};

// Template Implementations

template <typename Container>
void PmergeMe::printAfter(const Container &c) const {
	std::cout << "After:  ";
	int limit = (c.size() > (size_t)n_print) ? n_print : c.size();

	typename Container::const_iterator it = c.begin();
	for (int i = 0; i < limit; i++, it++) {
		std::cout << *it << " ";
	}

	if (c.size() > (size_t)n_print) {
		std::cout << "[...]";
	}
	std::cout << std::endl;
}

#endif