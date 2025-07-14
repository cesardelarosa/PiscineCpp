#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : value(0) {}

Fixed::Fixed(const Fixed& copy) {
    *this = copy;
}

Fixed::Fixed(const int n) {
    this->value = n << nFractBits;
}

Fixed::Fixed(const float f) {
    this->value = roundf(f * (1 << nFractBits));
}

Fixed::~Fixed(void) {}

Fixed&  Fixed::operator=(const Fixed& rhs) {
    if (this != &rhs)
        this->value = rhs.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const {
    return this->value;
}

void Fixed::setRawBits(int const raw) {
    this->value = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->value) / (1 << nFractBits);
}

int Fixed::toInt(void) const {
    return this->value >> nFractBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return (os);
}

bool Fixed::operator>(const Fixed& rhs) const {
    return this->value > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed& rhs) const {
    return this->value < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed& rhs) const {
    return this->value >= rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed& rhs) const {
    return this->value <= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed& rhs) const {
    return this->value == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed& rhs) const {
    return this->value != rhs.getRawBits();
}

Fixed Fixed::operator+(const Fixed& rhs) const {
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed& rhs) const {
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed& rhs) const {
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed& rhs) const {
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed& Fixed::operator++(void) {
    this->value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    this->value++;
    return tmp;
}

Fixed& Fixed::operator--(void) {
    this->value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    this->value--;
    return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}