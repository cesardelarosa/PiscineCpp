/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 11:58:40 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/04/20 14:43:13 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>
# include <cstdlib>
# include "PhoneBook.hpp"

int	main(void)
{
	std::string	cmd;
	PhoneBook	phonebook;
	
	while (42)
	{
		std::cout << "> ";
		std::getline(std::cin, cmd);
		if (cmd == "EXIT")
			break ;
		if (cmd == "ADD")
			phonebook.add();
		else if (cmd == "SEARCH")
			phonebook.search();
	}
	return (0);
}
