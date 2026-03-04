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

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define PINK "\033[35m"
#define CYAN "\033[36m"

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

	size_t _vec_comparisons;
	size_t _deq_comparisons;

	bool compareVec(int a, int b);
	bool compareDeq(int a, int b);

	void printBefore(int argc, char **argv) const;

	template <typename Container> void printSequence(const Container &c) const;

	void validateSort() const;

	long getTime() const;

	// Template Declarations
	template <typename Container>
	void parseDataTemplate(Container &c, int argc, char **argv);

	void parseData(std::vector<int> &c, int argc, char **argv);
	void parseData(std::deque<int> &c, int argc, char **argv);

	std::vector<size_t> getInsertionOrder(size_t n);

	void fordJohnsonSort(std::vector<int> &vec);
	void fordJohnsonSort(std::deque<int> &deq);

	void fordJohnsonRecursive(std::vector<int> &vec, size_t stride);
	void fordJohnsonRecursive(std::deque<int> &deq, size_t stride);
};

// Template Implementations

template <typename Container>
void PmergeMe::printSequence(const Container &c) const {
	size_t limit = (c.size() > static_cast<size_t>(n_print))
					   ? static_cast<size_t>(n_print)
					   : c.size();

	typename Container::const_iterator it = c.begin();
	for (size_t i = 0; i < limit; i++, it++) {
		std::cout << *it << " ";
	}

	if (c.size() > static_cast<size_t>(n_print)) {
		std::cout << "[...]";
	}
	std::cout << std::endl;
}

template <typename Container>
void PmergeMe::parseDataTemplate(Container &c, int argc, char **argv) {
	for (int i = 1; i < argc; i++) {
		std::string str = argv[i];

		if (str.empty() || (str.length() == 1 && str[0] == '+')) {
			throw std::invalid_argument("Empty or invalid argument");
		}

		for (size_t j = 0; j < str.length(); j++) {
			if (!isdigit(str[j]) && !(j == 0 && str[j] == '+')) {
				throw std::invalid_argument("Invalid character in argument");
			}
		}

		char *endptr;
		errno = 0;
		long n = std::strtol(str.c_str(), &endptr, 10);

		if (errno == ERANGE || *endptr != '\0' || n < 0 ||
			n > std::numeric_limits<int>::max()) {
			throw std::invalid_argument("Argument out of range");
		}

		c.push_back(static_cast<int>(n));
	}
}

#endif
