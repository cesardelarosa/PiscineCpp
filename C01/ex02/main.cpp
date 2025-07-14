/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:22:32 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/07/08 21:22:32 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << &str << std::endl; 
    std::cout << stringPTR << std::endl; 
    std::cout << &stringREF << std::endl; 
    std::cout << str << std::endl; 
    std::cout << *stringPTR << std::endl; 
    std::cout << stringREF << std::endl; 
    return (0);
}