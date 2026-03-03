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

// Process Routine

void PmergeMe::process(int argc, char **argv) {
	struct timeval start, end;
	long time_vec, time_deq;

	gettimeofday(&start, NULL);
	parseData(_vector, argc, argv);
	fordJohnsonSort(_vector);
	gettimeofday(&end, NULL);
	time_vec =
		(end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);

	gettimeofday(&start, NULL);
	parseData(_deque, argc, argv);
	fordJohnsonSort(_deque);
	gettimeofday(&end, NULL);
	time_deq =
		(end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);

	printBefore(argc, argv);
	printAfter(_vector);
	printAfter(_deque);

	std::cout << "Time to process a range of " << _vector.size()
			  << " elements with std::vector : " << time_vec << " us"
			  << std::endl;
	std::cout << "Time to process a range of " << _deque.size()
			  << " elements with std::deque  : " << time_deq << " us"
			  << std::endl;
}

// Data Parsing

void PmergeMe::parseData(std::vector<int> &c, int argc, char **argv) {
	c.reserve(static_cast<size_t>(argc - 1));

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

void PmergeMe::parseData(std::deque<int> &c, int argc, char **argv) {
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

// Print Utils

void PmergeMe::printBefore(int argc, char **argv) const {
	std::cout << "Before: ";
	int limit = (argc - 1 > n_print) ? n_print : argc - 1;

	for (int i = 1; i <= limit; i++) {
		std::cout << argv[i] << " ";
	}

	if (argc - 1 > n_print) {
		std::cout << "[...]";
	}
	std::cout << std::endl;
}

// Jacobsthal Sequence Generator

std::vector<size_t> PmergeMe::getInsertionOrder(size_t n) {
	std::vector<size_t> order;
	if (n == 0) {
		return order;
	}

	std::vector<size_t> jacob;
	jacob.push_back(1);
	jacob.push_back(3);
	while (jacob.back() < n + 1) {
		jacob.push_back(jacob.back() + 2 * jacob[jacob.size() - 2]);
	}

	size_t last_jacob = 1;
	for (size_t i = 1; i < jacob.size(); i++) {
		size_t current_jacob = jacob[i];
		size_t top = (current_jacob > n + 1) ? n + 1 : current_jacob;

		for (size_t j = top; j > last_jacob; j--) {
			order.push_back(j - 2);
		}
		last_jacob = top;
		if (last_jacob == n + 1) {
			break;
		}
	}
	return order;
}

// Vector Algorithm Implementation

void PmergeMe::fordJohnsonSort(std::vector<int> &vec) {
	fordJohnsonRecursive(vec, 1);
}

void PmergeMe::fordJohnsonRecursive(std::vector<int> &vec, size_t stride) {
	size_t n_elements = vec.size() / stride;
	if (n_elements < 2) {
		return;
	}

	for (size_t i = 0; i < n_elements / 2; ++i) {
		size_t left_winner_idx = (2 * i + 1) * stride - 1;
		size_t right_winner_idx = (2 * i + 2) * stride - 1;

		if (vec[left_winner_idx] > vec[right_winner_idx]) {
			std::vector<int>::iterator left_start = vec.begin() + (2 * i) * stride;
			std::vector<int>::iterator left_end = left_start + stride;
			std::vector<int>::iterator right_start = vec.begin() + (2 * i + 1) * stride;
			
			std::swap_ranges(left_start, left_end, right_start);
		}
	}

	fordJohnsonRecursive(vec, stride * 2);

	std::vector<int> main_chain;
	std::vector<int> pend_chain;

	main_chain.reserve(vec.size());
	pend_chain.reserve(vec.size() / 2);

	main_chain.insert(main_chain.end(), vec.begin(), vec.begin() + 2 * stride);

	for (size_t i = 1; i < n_elements / 2; ++i) {
		pend_chain.insert(pend_chain.end(), vec.begin() + (2 * i) * stride, vec.begin() + (2 * i + 1) * stride);
		main_chain.insert(main_chain.end(), vec.begin() + (2 * i + 1) * stride, vec.begin() + (2 * i + 2) * stride);
	}

	size_t processed_size = (n_elements / 2) * 2 * stride;
	if (n_elements % 2 != 0) {
		pend_chain.insert(pend_chain.end(), vec.begin() + processed_size, vec.begin() + processed_size + stride);
		processed_size += stride;
	}

	size_t num_pend_blocks = pend_chain.size() / stride;
	std::vector<size_t> order = getInsertionOrder(num_pend_blocks); 
	
	std::vector<size_t> winner_positions(num_pend_blocks);
	for (size_t i = 0; i < winner_positions.size(); ++i) {
		winner_positions[i] = i + 2;
	}
	if (n_elements % 2 != 0) {
		winner_positions.back() = main_chain.size() / stride;
	}

	for (size_t i = 0; i < order.size(); ++i) {
		size_t pend_idx = order[i];
		int b_value = pend_chain[(pend_idx + 1) * stride - 1];

		size_t bound_block = winner_positions[pend_idx];
		
		size_t low = 0;
		size_t high = bound_block;
		while (low < high) {
			size_t mid = low + (high - low) / 2;
			if (main_chain[(mid + 1) * stride - 1] < b_value) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}

		std::vector<int>::iterator insert_pos = main_chain.begin() + low * stride;
		std::vector<int>::iterator pend_start = pend_chain.begin() + pend_idx * stride;
		std::vector<int>::iterator pend_end = pend_start + stride;
		
		main_chain.insert(insert_pos, pend_start, pend_end);

		for (size_t j = 0; j < winner_positions.size(); ++j) {
			if (winner_positions[j] >= low) {
				winner_positions[j]++;
			}
		}
	}

	main_chain.insert(main_chain.end(), vec.begin() + processed_size, vec.end());
	vec = main_chain;
}

// Deque Algorithm Implementation

void PmergeMe::fordJohnsonSort(std::deque<int> &deq) {
	fordJohnsonRecursive(deq, 1);
}

void PmergeMe::fordJohnsonRecursive(std::deque<int> &deq, size_t stride) {
	size_t n_elements = deq.size() / stride;
	if (n_elements < 2) {
		return;
	}

	for (size_t i = 0; i < n_elements / 2; ++i) {
		size_t left_winner_idx = (2 * i + 1) * stride - 1;
		size_t right_winner_idx = (2 * i + 2) * stride - 1;

		if (deq[left_winner_idx] > deq[right_winner_idx]) {
			std::deque<int>::iterator left_start = deq.begin() + (2 * i) * stride;
			std::deque<int>::iterator left_end = left_start + stride;
			std::deque<int>::iterator right_start = deq.begin() + (2 * i + 1) * stride;
			
			std::swap_ranges(left_start, left_end, right_start);
		}
	}

	fordJohnsonRecursive(deq, stride * 2);

	std::deque<int> main_chain;
	std::deque<int> pend_chain;

	main_chain.insert(main_chain.end(), deq.begin(), deq.begin() + 2 * stride);

	for (size_t i = 1; i < n_elements / 2; ++i) {
		pend_chain.insert(pend_chain.end(), deq.begin() + (2 * i) * stride, deq.begin() + (2 * i + 1) * stride);
		main_chain.insert(main_chain.end(), deq.begin() + (2 * i + 1) * stride, deq.begin() + (2 * i + 2) * stride);
	}

	size_t processed_size = (n_elements / 2) * 2 * stride;
	if (n_elements % 2 != 0) {
		pend_chain.insert(pend_chain.end(), deq.begin() + processed_size, deq.begin() + processed_size + stride);
		processed_size += stride;
	}

	size_t num_pend_blocks = pend_chain.size() / stride;
	std::vector<size_t> order = getInsertionOrder(num_pend_blocks); 
	
	std::vector<size_t> winner_positions(num_pend_blocks);
	for (size_t i = 0; i < winner_positions.size(); ++i) {
		winner_positions[i] = i + 2;
	}
	if (n_elements % 2 != 0) {
		winner_positions.back() = main_chain.size() / stride;
	}

	for (size_t i = 0; i < order.size(); ++i) {
		size_t pend_idx = order[i];
		int b_value = pend_chain[(pend_idx + 1) * stride - 1];

		size_t bound_block = winner_positions[pend_idx];
		
		size_t low = 0;
		size_t high = bound_block;
		while (low < high) {
			size_t mid = low + (high - low) / 2;
			if (main_chain[(mid + 1) * stride - 1] < b_value) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}

		std::deque<int>::iterator insert_pos = main_chain.begin() + low * stride;
		std::deque<int>::iterator pend_start = pend_chain.begin() + pend_idx * stride;
		std::deque<int>::iterator pend_end = pend_start + stride;
		
		main_chain.insert(insert_pos, pend_start, pend_end);

		for (size_t j = 0; j < winner_positions.size(); ++j) {
			if (winner_positions[j] >= low) {
				winner_positions[j]++;
			}
		}
	}

	main_chain.insert(main_chain.end(), deq.begin() + processed_size, deq.end());
	deq = main_chain;
}