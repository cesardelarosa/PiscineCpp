#ifndef SPAN_HPP
#define SPAN_HPP

#include <stdexcept>
#include <vector>

class Span {
  public:
	Span(unsigned int n);
	Span(const Span &src);
	Span &operator=(const Span &src);
	~Span();

	void addNumber(int n);
	long shortestSpan() const;
	long longestSpan() const;

	template <typename T> void addNumbers(T begin, T end) {
		if (std::distance(begin, end) + _storage.size() > _n) {
			throw std::runtime_error("Span capacity exceeded");
		}
		_storage.insert(_storage.end(), begin, end);
	}

  private:
	unsigned int _n;
	std::vector<int> _storage;
};

#endif
