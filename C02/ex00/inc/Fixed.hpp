#pragma once

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
  public:
	Fixed();
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &copy);
	~Fixed();

	int getRawBits() const;
	void setRawBits(int const raw);

  private:
	int value;
	static const int nFractBits = 8;
};

#endif	// FIXED_HPP