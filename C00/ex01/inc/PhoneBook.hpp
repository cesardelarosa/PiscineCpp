#pragma once

#ifndef PHONEBOOK_C
#define PHONEBOOK_C

#include "Contact.hpp"
#include <cstddef>

class PhoneBook {
  public:
	PhoneBook();
	~PhoneBook();

	void add();
	void search();

  private:
	static const size_t _max = 8;
	Contact _contacts[_max];
	size_t _next;
	size_t _count;
};

#endif // PHONEBOOK_C