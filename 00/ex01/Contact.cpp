#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

std::string Contact::get_first() const
{
	return this->first_name;
}

std::string Contact::get_last() const
{
	return this->last_name;
}

std::string Contact::get_nick() const{
	return this->nick;
}

std::string Contact::get_num() const{
	return this->phone_number;
}

std::string Contact::get_secret() const
{
	return this->secret;
}


void Contact::set_first_name(std::string fname)
{
	this->first_name = fname;
}

void Contact::set_last_name(std::string lname)
{
	this->last_name = lname;
}

void Contact::set_nick(std::string nick)
{
	this->nick = nick;
}

void Contact::set_num(std::string num)
{
	this->phone_number = num;
}

void Contact::set_secret(std::string secret)
{
	this->secret = secret;
}