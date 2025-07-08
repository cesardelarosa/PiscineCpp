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
#include <sstream>

PhoneBook::PhoneBook() : _next(0), _count(0) { }

PhoneBook::~PhoneBook() { }

void PhoneBook::add()
{
    _contacts[_next].fillFromPrompt();
    _next = (_next + 1) % _max;
    if (_count < _max)
        _count++;
}

void PhoneBook::search()
{
    for (int i = 0; i < _count; i++)
        _contacts[i].printRow(i);
    if (_count == 0)
    {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }
    std::cout << "Enter index to view details (0 to " << _count - 1 << "): ";
    std::string line;
    if (!std::getline(std::cin, line))
        return;
    std::stringstream ss(line);
    int index;
    if (!(ss >> index) || !ss.eof())
    {
        std::cout << "Error: Invalid input. Please enter a number." << std::endl;
		return ;
    }
    if (index >= 0 && index < _count)
        _contacts[index].printCard();
    else
        std::cout << "Error: Index out of range." << std::endl;
}