#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
	std::cout << "Constructor created for 8 contact." << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook class Destroyed" << std::endl;
}


Contact	PhoneBook::get_contact(int index)
{
	return (this->contacts[index % 8]);
}

void PhoneBook::print(Contact contact)
{
	std::cout << "Pulling up contact information\n";
	if (contact.get_first().size() == 0 || contact.get_last().size() == 0 || contact.get_nick().size() == 0 || contact.get_nick().size() == 0 || contact.get_num().size() == 0 || contact.get_secret().size() == 0)
	{
		std::cout << "Something went wrong!\n";
		return ;
	}
	std::cout << "First Name: " << contact.get_first() << std::endl;
	std::cout << "Last Name: " << contact.get_last() << std::endl;
	std::cout << "Nick: " << contact.get_nick() << std::endl;
	std::cout << "Phone Number: " << contact.get_num() << std::endl;
	std::cout << "Secret: " << contact.get_secret() << std::endl;
}

static std::string get_input(const std::string &prompt) {
	std::string input;
	while (!std::cin.eof() && input.empty()) {
		std::cout << prompt;
		std::getline(std::cin, input);
	}
	return input;
}

void PhoneBook::add()
{
	Contact &contact = this->contacts[this->index % 8];

	if (this->index > 7)
		std::cout << "Warning: overwriting info about " << contact.get_first() << std::endl;

	contact.set_first_name(get_input("Enter a first name: "));
	contact.set_last_name(get_input("Enter " + contact.get_first() + "'s last name: "));
	contact.set_nick(get_input("Enter " + contact.get_first() + "'s nickname: "));
	contact.set_num(get_input("Enter " + contact.get_first() + "'s phone number: "));
	contact.set_secret(get_input("Enter " + contact.get_first() + "'s darkest secret: "));

	std::cout << contact.get_first() << " successfully added to phonebook [" 
			  << (this->index % 8) + 1 << "/8]" << std::endl;

	this->index++;
}

static std::string	fix_width(std::string str, long unsigned max)
{
	if (str.size() > max)
	{
		str.resize(max);
		str[str.size() - 1] = '.';
	}
	return (str);
}

void PhoneBook::search()
{
    if (this->contacts[0].get_first().empty()) {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }

    std::cout << "Index | First Name | Last Name  | Nickname" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;

    for (int i = 0; i < 8; i++) {
        if (!this->contacts[i].get_first().empty()) {
            std::cout << "  " << i + 1 << "   | "
                      << fix_width(this->contacts[i].get_first(), 10) << " | "
                      << fix_width(this->contacts[i].get_last(), 10) << " | "
                      << fix_width(this->contacts[i].get_nick(), 10) << std::endl;
        }
    }

    std::cout << "-----------------------------------------" << std::endl;

    std::string input;
    while (!std::cin.eof()) {
        std::cout << "Select an index (1-8): ";
        if (std::getline(std::cin, input) && input.size() == 1 && input[0] >= '1' && input[0] <= '8') {
            int idx = input[0] - '1';
            if (!this->contacts[idx].get_first().empty()) {
                this->print(this->contacts[idx]);
                return;
            }
        }
        std::cout << "Invalid index! Please try again." << std::endl;
    }
}