#include "PmergeMe.hpp"
#include <sys/time.h>

// Orthodox Canonical Form

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) { *this = src; }

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
	if (this != &rhs) {
		this->_deque = rhs._deque;
		this->_vector = rhs._vector;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

// Public Method

void PmergeMe::process(int argc, char **argv) {
	struct timeval start, end;
	long time_vec, time_deq;

	gettimeofday(&start, NULL);
	parseData(_vector, argc, argv);
	fordJohnsonSort(_vector);
	gettimeofday(&end, NULL);
	time_vec = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);

	gettimeofday(&start, NULL);
	parseData(_deque, argc, argv);
	fordJohnsonSort(_deque);
	gettimeofday(&end, NULL);
	time_deq = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);

	printBefore(argc, argv);
	printAfter(_vector);

	std::cout << "Time to process a range of " << _vector.size()
	          << " elements with std::vector : " << time_vec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size()
	          << " elements with std::deque  : " << time_deq << " us" << std::endl;
}

// Private Utils

void PmergeMe::printBefore(int argc, char **argv) const {
	std::cout << "Before: ";
	int limit = (argc - 1 > 5) ? 5 : argc - 1;

	for (int i = 1; i <= limit; i++) {
		std::cout << argv[i] << " ";
	}

	if (argc - 1 > 5) {
		std::cout << "[...]";
	}
	std::cout << std::endl;
}

std::vector<int> PmergeMe::getInsertionOrder(int n_pairs) {
	std::vector<int> order;
	std::vector<int> jacob;

	jacob.push_back(1);
	jacob.push_back(3);
	while (jacob.back() < n_pairs) {
		jacob.push_back(jacob.back() + 2 * jacob[jacob.size() - 2]);
	}

	int last_jacob = 1;
	for (size_t i = 1; i < jacob.size(); i++) {
		int current_jacob = jacob[i];
		int top = (current_jacob > n_pairs) ? n_pairs : current_jacob;

		for (int j = top; j > last_jacob; j--) {
			order.push_back(j);
		}
		last_jacob = top;
		if (last_jacob == n_pairs) {
			break;
		}
	}
	return order;
}

void PmergeMe::fordJohnsonSort(std::vector<int> &vec){
	if (vec.size() < 2) {
		return;
	}

	bool has_straggler = vec.size() % 2;
	int straggler = -1;
	if (has_straggler) {
		straggler = vec.back();
		vec.pop_back();
	}

	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < vec.size(); i += 2) {
		pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
	}

	sortPairs(pairs);
	
	std::vector<int> main;
	std::vector<int> pend;

	main.push_back(pairs[0].second);
	main.push_back(pairs[0].first);
	for (size_t i = 1; i < pairs.size(); i++) {
		main.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}

	std::vector<int> order = getInsertionOrder(main.size());
	
	for (size_t i = 0; i < order.size(); i++) {
		int target = pend[order[i] - 1];
		std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), target);
		main.insert(pos, target);
	}

	if (has_straggler) {
		std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), straggler);
		main.insert(pos, straggler);
	}

	vec = main;
}

void PmergeMe::fordJohnsonSort(std::deque<int> &deq) {
	(void)deq;
}
