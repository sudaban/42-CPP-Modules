#include "Harl.h"
#include <iostream>

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my "
	          << "7XL-double-cheese-triple-pickle-special-ketchup burger. "
	          << "I really do!" << std::endl;
	return;
}

void Harl::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger! "
	          << "If you did, I wouldn’t be asking for more!" << std::endl;
	return;
}

void Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month."
	          << std::endl;
	return;
}

void Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	return;
}

void Harl::complain(std::string level) {
	typedef void (Harl::*HarlFuncPtr)(void);

	const std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	HarlFuncPtr funcs[4] = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i = 0; i < 4; ++i) {
		if (levels[i] == level) {
			(this->*funcs[i])();
			return;
		}
	}
}
