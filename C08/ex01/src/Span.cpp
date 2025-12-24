#include "Span.hpp"
#include <algorithm>

Span::Span(unsigned int n) : _n(n) { _storage.reserve(n); }

Span::Span(const Span &src) { *this = src; }

Span &Span::operator=(const Span &src) {
	if (this != &src) {
		this->_n = src._n;
		this->_storage = src._storage;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
	if (_storage.size() >= _n) {
		throw std::runtime_error("Span is already full");
	}
	_storage.push_back(num);
}

long Span::shortestSpan() const {
	if (_storage.size() < 2) {
		throw std::runtime_error("Not enough numbers for a span");
	}

	std::vector<int> sorted = _storage;
	std::sort(sorted.begin(), sorted.end());

	long min_diff = -1;
	for (size_t i = 1; i < sorted.size(); i++) {
		long diff = static_cast<long>(sorted[i]) - sorted[i - 1];
		if (min_diff == -1 || diff < min_diff) {
			min_diff = diff;
		}
	}

	return min_diff;
}

long Span::longestSpan() const {
	if (_storage.size() < 2) {
		throw std::runtime_error("Not enough numbers for a span");
	}

	int min_val = *std::min_element(_storage.begin(), _storage.end());
	int max_val = *std::max_element(_storage.begin(), _storage.end());

	return static_cast<long>(max_val) - min_val;
}
