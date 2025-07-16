#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : value(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
  std::cout << "Copy constructor called" << std::endl;
  *this = copy;
}

Fixed::Fixed(const int n) {
  std::cout << "Int constructor called" << std::endl;
  this->value = n << this->nFractBits;
}

Fixed::Fixed(const float f) {
  std::cout << "Float constructor called" << std::endl;
  this->value = roundf(f * (1 << this->nFractBits));
}

Fixed &Fixed::operator=(const Fixed &copy) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &copy)
    this->value = copy.getRawBits();
  return *this;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
  os << fixed.toFloat();
  return os;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits() const {
  std::cout << "getRawBits called" << std::endl;
  return value;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits called" << std::endl;
  value = raw;
}

float Fixed::toFloat() const {
  return static_cast<float>(this->value) / (1 << this->nFractBits);
}

int Fixed::toInt() const {
  return static_cast<int>(this->value >> this->nFractBits);
}