#include "PhoneBook.hpp"

int main()
{
    PhoneBook pbook;
    std::string command;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT) > ";
        if (!std::getline(std::cin, command) || command == "EXIT")
        {
            std::cout << "\nExiting phonebook..." << std::endl;
            break;
        }

        if (command == "ADD")
            pbook.add();
        else if (command == "SEARCH")
            pbook.search();
        else
            std::cout << "Invalid command! Please enter ADD, SEARCH, or EXIT." << std::endl;
    }
    return 0;
}
