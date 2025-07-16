#pragma once
#include <iostream>

class Fixed {
public:
  Fixed();
  Fixed(const Fixed &copy);
  Fixed(const int n);
  Fixed(const float f);
  ~Fixed();

  Fixed &operator=(const Fixed &copy);

  int getRawBits() const;
  void setRawBits(int const raw);
  float toFloat() const;
  int toInt() const;

private:
  int value;
  static const int nFractBits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);