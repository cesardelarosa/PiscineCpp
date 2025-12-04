#include <cstddef>
#include <exception>

template <typename T> Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(Array const &other) : _array(NULL), _size(0) {
	*this = other;
}

template <typename T> Array<T> &Array<T>::operator=(const Array &other) {
	if (this != &other) {
		if (_array)
			delete[] _array;
		_size = other._size;
		_array = new T[_size]();
		for (unsigned int i = 0; i < _size; i++) {
			_array[i] = other._array[i];
		}
	}
	return *this;
}

template <typename T> Array<T>::~Array() {
	if (_array)
		delete[] _array;
}

template <typename T> T &Array<T>::operator[](unsigned int i) {
	if (i >= _size)
		throw std::exception();
	return _array[i];
}

template <typename T> const T &Array<T>::operator[](unsigned int i) const {
	if (i >= _size)
		throw std::exception();
	return _array[i];
}

template <typename T> unsigned int Array<T>::size() const {
	return this->_size;
}
