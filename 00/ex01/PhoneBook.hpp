#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include "Contact.hpp"


class PhoneBook
{
private:
	Contact contacts[8];
	int index;
public:
	PhoneBook();
	~PhoneBook();

	void add();
	void search();
	void print(Contact contact);

	Contact get_contact(int index);
};



#endif // PHONEBOOK_HPP