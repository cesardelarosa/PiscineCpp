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

	void parseData(std::vector<int> &c, int argc, char **argv);
	void parseData(std::deque<int> &c, int argc, char **argv);

	void printBefore(int argc, char **argv) const;

	std::vector<int> getInsertionOrder(int n_pairs);

	void fordJohnsonSort(std::vector<int> &vec);
	void fordJohnsonSort(std::deque<int> &deq);

	template <typename Iterator> void sortPairs(Iterator begin, Iterator end);

	template <typename Container> void printAfter(const Container &c) const;
};

// Template Implementations

template <typename Iterator>
void PmergeMe::sortPairs(Iterator begin, Iterator end) {
	if (std::distance(begin, end) < 2) {
		return;
	}

	Iterator mid = begin + std::distance(begin, end) / 2;

	sortPairs(begin, mid);
	sortPairs(mid, end);

	typedef typename std::iterator_traits<Iterator>::value_type value_type;
	std::vector<value_type> temp;
	temp.reserve(std::distance(begin, end));

	Iterator i = begin;
	Iterator j = mid;

	while (i != mid && j != end) {
		if (i->first <= j->first) {
			temp.push_back(*i++);
		} else {
			temp.push_back(*j++);
		}
	}
	while (i != mid) {
		temp.push_back(*i++);
	}
	while (j != end) {
		temp.push_back(*j++);
	}

	std::copy(temp.begin(), temp.end(), begin);
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
