#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename F> void iter(T *array, size_t len, F f) {
	if (!array)
		return;
	for (size_t i = 0; i < len; i++) {
		f(array[i]);
	}
}

#endif
