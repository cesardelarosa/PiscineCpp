/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:59:07 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/04/19 20:20:54 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

#define SILENCE "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << SILENCE << std::endl;
		return (0);
	}
	while (*(++argv))
	{
		while (**argv)
			std::cout << (char)std::toupper(*(*argv)++);
		std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}
