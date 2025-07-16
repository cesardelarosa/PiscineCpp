/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:42:24 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/07/08 19:42:24 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

#define ANNOUNCE "BraiiiiiiinnnzzzZ..."

Zombie::Zombie() {}

Zombie::~Zombie() {
  std::cout << this->_name << " has been destroyed." << std::endl;
}

void Zombie::setName(std::string name) { _name = name; }

void Zombie::announce() {
  std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}