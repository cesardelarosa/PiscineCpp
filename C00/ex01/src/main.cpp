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

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

typedef void (PhoneBook::*t_func)();

struct s_command
{
    std::string name;
    t_func      function;
};

const s_command* get_commands()
{
    static const s_command commands[] = {
        {"ADD", &PhoneBook::add},
        {"SEARCH", &PhoneBook::search},
        {"", NULL}
    };
    return commands;
}

int main(void)
{
    PhoneBook phonebook;
    std::string cmd;
    const s_command* commands = get_commands();

    while (true)
    {
        std::cout << "> ";
        if (!std::getline(std::cin, cmd) || cmd == "EXIT")
            break;
        for (int i = 0; !commands[i].name.empty(); ++i)
        {
            if (cmd == commands[i].name)
            {
                (phonebook.*(commands[i].function))();
                break;
            }
        }
    }
    return (0);
}