#ifndef PMERGEME_HPP
#define PMERGEME_HPP

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

	std::vector<int> getInsertionOrder(int n_pairs);
	
	void fordJohnsonSort(std::vector<int> &vec);
	void fordJohnsonSort(std::deque<int> &deq);

	template <typename PairContainer>
	void sortPairs(PairContainer &pairs);

	template <typename Container>
	void parseData(Container &c, int argc, char **argv);

	template <typename Container>
	void printAfter(const Container &c) const;
};

// Template Implementations

template <typename PairContainer>
void PmergeMe::sortPairs(PairContainer &pairs) {
	if (pairs.size() < 2) {
		return;
	}

	size_t mid = pairs.size() / 2;
	PairContainer left(pairs.begin(), pairs.begin() + mid);
	PairContainer right(pairs.begin() + mid, pairs.end());

	sortPairs(left);
	sortPairs(right);

	size_t i = 0, j = 0, k = 0;
	while (i < left.size() && j < right.size()) {
		if (left[i].first <= right[j].first){
			pairs[k++] = left[i++];
		} else {
			pairs[k++] = right[j++];
		}
	}
	while (i < left.size()) {
		pairs[k++] = left[i++];
	}
	while (j < right.size()) {
		pairs[k++] = right[j++];
	}
}

template <typename Container>
void PmergeMe::parseData(Container &c, int argc, char **argv) {
	for (int i = 1; i < argc; i++) {
		std::string str = argv[i];

		if (str.empty()) {
			throw std::invalid_argument("Empty argument");
		}

		for (size_t j = 0; j < str.length(); j++) {
			if (!isdigit(str[j]) && !(j == 0 && str[j] == '+')) {
				throw std::invalid_argument("Invalid character in argument");
			}
		}

		long n = std::atol(str.c_str());
		if (n < 0 || n > std::numeric_limits<int>::max()) {
			throw std::invalid_argument("Argument out of range");
		}

		c.push_back(static_cast<int>(n));
	}
}

template <typename Container>
void PmergeMe::printAfter(const Container &c) const {
	std::cout << "After:  ";
	int limit = (c.size() > n_print) ? n_print : c.size();

	typename Container::const_iterator it = c.begin();
	for (int i = 0; i < limit; i++, it++) {
		std::cout << *it << " ";
	}

	if (c.size() > n_print) {
		std::cout << "[...]";
	}
	std::cout << std::endl;
}

#endif
