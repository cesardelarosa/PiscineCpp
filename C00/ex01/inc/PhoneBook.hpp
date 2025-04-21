/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 11:44:53 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/04/20 11:47:42 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Contact.hpp"

class	PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();

		void	add();
		void	search() const;

	private:
		static const int	_max = 8;
		Contact				_contacts[_max];
		int					_next;
		int					_count;
};
