#include "PmergeMe.hpp"
#include <sys/time.h>

// Orthodox Canonical Form

PmergeMe::PmergeMe() : _vec_comparisons(0), _deq_comparisons(0) {}

PmergeMe::PmergeMe(const PmergeMe &src) { *this = src; }

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
	if (this != &rhs) {
		this->_deque = rhs._deque;
		this->_vector = rhs._vector;
		this->_vec_comparisons = rhs._vec_comparisons;
		this->_deq_comparisons = rhs._deq_comparisons;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

// Count comparisons
bool PmergeMe::compareVec(int a, int b) {
	_vec_comparisons++;
	return a < b;
}

bool PmergeMe::compareDeq(int a, int b) {
	_deq_comparisons++;
	return a < b;
}

// Validation Utils

void PmergeMe::validateSort() const {
	if (_vector.size() != _deque.size()) {
		throw std::logic_error("Error: Containers have different sizes.");
	}

	if (_vector.empty()) {
		return;
	}

	if (_vector[0] != _deque[0]) {
		throw std::logic_error("Error: Container results do not match.");
	}

	for (size_t i = 1; i < _vector.size(); i++) {
		if (_vector[i - 1] > _vector[i]) {
			throw std::logic_error(
				"Error: std::vector is not sorted correctly.");
		}
		if (_deque[i - 1] > _deque[i]) {
			throw std::logic_error(
				"Error: std::deque is not sorted correctly.");
		}
		if (_vector[i] != _deque[i]) {
			throw std::logic_error("Error: Container results do not match.");
		}
	}
}

long PmergeMe::getTime() const {
	struct timeval time;
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000L) + time.tv_usec;
}

// Process Routine

void PmergeMe::process(int argc, char **argv) {
	long time_vec_parse, time_vec_sort, time_vec_total;
	long time_deq_parse, time_deq_sort, time_deq_total;
	long start;

	// Reseteamos contadores
	_vec_comparisons = 0;
	_deq_comparisons = 0;

	// Vector Phase

	start = getTime();
	parseData(_vector, argc, argv);
	time_vec_parse = getTime() - start;

	std::vector<int> parsed_sequence = _vector;

	start = getTime();
	fordJohnsonSort(_vector);
	time_vec_sort = getTime() - start;

	time_vec_total = time_vec_parse + time_vec_sort;

	// Deque Phase

	start = getTime();
	parseData(_deque, argc, argv);
	time_deq_parse = getTime() - start;

	start = getTime();
	fordJohnsonSort(_deque);
	time_deq_sort = getTime() - start;

	time_deq_total = time_deq_parse + time_deq_sort;

	// Validation Phase

	validateSort();

	// Printing Phase

	std::cout << RED << "Before: " << RESET;
	printSequence(parsed_sequence);

	std::cout << GREEN << "After:  " << RESET;
	printSequence(_vector);

	std::cout << "Time to process a range of " << PINK << _vector.size()
			  << RESET << " elements with " << CYAN << "std::vector" << RESET
			  << ": " << YELLOW << time_vec_total << " us" << RESET
			  << " (Parse: " << time_vec_parse
			  << " us | Sort: " << time_vec_sort << " us & " << _vec_comparisons
			  << " comparisons)" << std::endl;

	std::cout << "Time to process a range of " << PINK << _deque.size() << RESET
			  << " elements with " << BLUE << "std::deque" << RESET << ":  "
			  << YELLOW << time_deq_total << " us" << RESET
			  << " (Parse: " << time_deq_parse
			  << " us | Sort: " << time_deq_sort << " us & " << _deq_comparisons
			  << " comparisons)" << std::endl;
}

// Data Parsing

void PmergeMe::parseData(std::vector<int> &c, int argc, char **argv) {
	c.reserve(static_cast<size_t>(argc - 1));
	parseDataTemplate(c, argc, argv);
}

void PmergeMe::parseData(std::deque<int> &c, int argc, char **argv) {
	parseDataTemplate(c, argc, argv);
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

		if (compareVec(vec[right_winner_idx], vec[left_winner_idx])) {
			std::vector<int>::iterator left_start =
				vec.begin() + (2 * i) * stride;
			std::vector<int>::iterator left_end = left_start + stride;
			std::vector<int>::iterator right_start =
				vec.begin() + (2 * i + 1) * stride;

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
		pend_chain.insert(pend_chain.end(), vec.begin() + (2 * i) * stride,
						  vec.begin() + (2 * i + 1) * stride);
		main_chain.insert(main_chain.end(), vec.begin() + (2 * i + 1) * stride,
						  vec.begin() + (2 * i + 2) * stride);
	}

	size_t processed_size = (n_elements / 2) * 2 * stride;
	if (n_elements % 2 != 0) {
		pend_chain.insert(pend_chain.end(), vec.begin() + processed_size,
						  vec.begin() + processed_size + stride);
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

			if (compareVec(main_chain[(mid + 1) * stride - 1], b_value)) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}

		std::vector<int>::iterator insert_pos =
			main_chain.begin() + low * stride;
		std::vector<int>::iterator pend_start =
			pend_chain.begin() + pend_idx * stride;
		std::vector<int>::iterator pend_end = pend_start + stride;

		main_chain.insert(insert_pos, pend_start, pend_end);

		for (size_t j = 0; j < winner_positions.size(); ++j) {
			if (winner_positions[j] >= low) {
				winner_positions[j]++;
			}
		}
	}

	main_chain.insert(main_chain.end(), vec.begin() + processed_size,
					  vec.end());
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

		if (compareDeq(deq[right_winner_idx], deq[left_winner_idx])) {
			std::deque<int>::iterator left_start =
				deq.begin() + (2 * i) * stride;
			std::deque<int>::iterator left_end = left_start + stride;
			std::deque<int>::iterator right_start =
				deq.begin() + (2 * i + 1) * stride;

			std::swap_ranges(left_start, left_end, right_start);
		}
	}

	fordJohnsonRecursive(deq, stride * 2);

	std::deque<int> main_chain;
	std::deque<int> pend_chain;

	main_chain.insert(main_chain.end(), deq.begin(), deq.begin() + 2 * stride);

	for (size_t i = 1; i < n_elements / 2; ++i) {
		pend_chain.insert(pend_chain.end(), deq.begin() + (2 * i) * stride,
						  deq.begin() + (2 * i + 1) * stride);
		main_chain.insert(main_chain.end(), deq.begin() + (2 * i + 1) * stride,
						  deq.begin() + (2 * i + 2) * stride);
	}

	size_t processed_size = (n_elements / 2) * 2 * stride;
	if (n_elements % 2 != 0) {
		pend_chain.insert(pend_chain.end(), deq.begin() + processed_size,
						  deq.begin() + processed_size + stride);
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

			if (compareDeq(main_chain[(mid + 1) * stride - 1], b_value)) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}

		std::deque<int>::iterator insert_pos =
			main_chain.begin() + low * stride;
		std::deque<int>::iterator pend_start =
			pend_chain.begin() + pend_idx * stride;
		std::deque<int>::iterator pend_end = pend_start + stride;

		main_chain.insert(insert_pos, pend_start, pend_end);

		for (size_t j = 0; j < winner_positions.size(); ++j) {
			if (winner_positions[j] >= low) {
				winner_positions[j]++;
			}
		}
	}

	main_chain.insert(main_chain.end(), deq.begin() + processed_size,
					  deq.end());
	deq = main_chain;
}
