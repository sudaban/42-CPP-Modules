#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>


class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nick;
	std::string phone_number;
	std::string secret;
public:
	Contact();
	~Contact();

	//getters
	std::string get_first() const;
	std::string get_last() const;
	std::string get_nick() const;
	std::string get_num() const;
	std::string get_secret() const;
	//getters
	
	//setters
	void set_first_name(std::string name);
	void set_last_name(std::string name);
	void set_nick(std::string nick);
	void set_num(std::string num);
	void set_secret(std::string secret);
	//setters
};


#endif //CONTACT_HPP