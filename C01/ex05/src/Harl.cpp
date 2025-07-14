#include <iostream>
#include <string>
#include "Harl.hpp"

#define DEBUG_MSG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
#define INFO_MSG "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
#define WARNING_MSG "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
#define ERROR_MSG "This is unacceptable! I want to speak to the manager now."

void    Harl::debug()
{
    std::cout << "[DEBUG] " << DEBUG_MSG << std::endl;
}

void    Harl::info()
{
    std::cout << "[INFO] " << INFO_MSG << std::endl;
}

void    Harl::warning()
{
    std::cout << "[WARNING] " << WARNING_MSG << std::endl;
}

void    Harl::error()
{
    std::cout << "[ERROR] " << ERROR_MSG << std::endl;
}

void    Harl::complain(std::string level)
{
    std::string levels[] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };

    void (Harl::*complaintFunctions[])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*(complaintFunctions[i]))();
            return;
        }
    }
}

Harl::Harl() {}
Harl::~Harl() {}
