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
#include <string>

Contact::Contact() : _firstName(""), _lastName(""), _nickName(""),
                     _phoneNumber(""), _darkestSecret("") { }

Contact::~Contact() { }

typedef struct s_field
{
	const char				*prompt;
	std::string	Contact::	*member;
}	t_field;

void Contact::fillFromPrompt()
{
	const t_field	fields[] = {
		{"First Name", &Contact::_firstName},
		{"Last Name", &Contact::_lastName},
		{"Nickname", &Contact::_nickName},
		{"Phone Number", &Contact::_phoneNumber},
		{"Darkest Secret", &Contact::_darkestSecret}
	};
	const int	n = sizeof(fields) / sizeof(fields[0]);

	for (int i = 0; i < n; i++)
	{
		std::string	tmp;
		do {
			std::cout << fields[i].prompt << ": ";
			std::getline(std::cin, tmp);
		} while (tmp.empty());
		this->*(fields[i].member) = tmp;
		std::cout << std::endl;
	}
}

static std::string	formatField(const std::string& s)
{
	if (s.size() <= 10)
		return (s);
	return (s.substr(0, 9) + ".");
}

void Contact::printRow(int index) const
{
    std::cout << std::setw(10) << std::right
		<< index << "|";
    std::cout << std::setw(10) << std::right
		<< formatField(_firstName) << "|";
    std::cout << std::setw(10) << std::right
		<< formatField(_lastName) << "|";
    std::cout << std::setw(10) << std::right
		<< formatField(_nickName) << std::endl;
}

void Contact::printCard() const {
}
