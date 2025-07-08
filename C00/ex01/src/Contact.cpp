/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:45:56 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/04/20 18:31:21 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

const Contact::t_field Contact::_fields[] = {
    {"First Name", &Contact::_firstName},
    {"Last Name", &Contact::_lastName},
    {"Nickname", &Contact::_nickName},
    {"Phone Number", &Contact::_phoneNumber},
    {"Darkest Secret", &Contact::_darkestSecret},
    {NULL, NULL}
};

Contact::Contact() { }
Contact::~Contact() { }

void Contact::fillFromPrompt()
{
    for (int i = 0; _fields[i].prompt; i++)
    {
        std::string tmp;
        do {
            std::cout << _fields[i].prompt << ": ";
            std::getline(std::cin, tmp);
        } while (tmp.empty());
        this->*(_fields[i].member) = tmp;
    }
    std::cout << std::endl;
}

void Contact::printCard() const
{
    for (int i = 0; _fields[i].prompt; i++)
    {
        std::cout << _fields[i].prompt << ": " << this->*(_fields[i].member) << std::endl;
    }
}

static std::string formatField(const std::string& s)
{
    if (s.size() <= 10)
        return (s);
    return (s.substr(0, 9) + ".");
}

void Contact::printRow(int index) const
{
    std::cout << std::setw(10) << std::right << index << "|";
    std::cout << std::setw(10) << std::right << formatField(_firstName) << "|";
    std::cout << std::setw(10) << std::right << formatField(_lastName) << "|";
    std::cout << std::setw(10) << std::right << formatField(_nickName) << std::endl;
}