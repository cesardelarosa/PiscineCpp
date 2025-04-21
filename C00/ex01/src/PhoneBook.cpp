/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:44:31 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/04/20 18:29:29 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook() : _next(0), _count(0) { }

PhoneBook::~PhoneBook() { }

void PhoneBook::add()
{
	_contacts[_next].fillFromPrompt();
	_next = (_next + 1) % _max;
	_count += _count < _max;
}

void PhoneBook::search() const
{
	for (int i = 0; i < _count; i++)
		_contacts[i].printRow(i);
}

