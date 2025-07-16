#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main() {
    PhoneBook   phonebook;
    std::string cmd;

    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, cmd)) {
            break;
        }
        
        if (cmd == "EXIT") {
            break;
        } else if (cmd == "ADD") {
            phonebook.add();
        } else if (cmd == "SEARCH") {
            phonebook.search();
        }
    }

    return 0;
}
