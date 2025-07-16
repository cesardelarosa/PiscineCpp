/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 20:09:21 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/07/08 20:09:21 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
  int n = 5;
  std::string name = "zombie";
  Zombie *horde = zombieHorde(n, name);
  for (int i = 0; i < n; i++) {
    horde[i].announce();
  }
  delete[] horde;
  return 0;
}