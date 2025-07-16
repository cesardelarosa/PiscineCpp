/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:49:41 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/07/08 18:59:10 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class	Zombie
{
	public:

		Zombie();
		~Zombie();

		void	announce();
		void	setName(std::string name);
	
	private:
	
		std::string	_name;
};

Zombie	*zombieHorde(int N, std::string name);
