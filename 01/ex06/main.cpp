#include "Harl.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
	const std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	if (argc != 2) {
		std::cerr << "Usage: ./harlFilter <LEVEL>" << std::endl;
		return 1;
	}

	int log_level = -1;
	for (int i = 0; i < 4; ++i) {
		if (levels[i] == argv[1]) {
			log_level = i;
			break;
		}
	}

	Harl harl;

	switch (log_level) {
		case 0:
			harl.complain("DEBUG");
			std::cout << std::endl;
			// fall through
		case 1:
			harl.complain("INFO");
			std::cout << std::endl;
			// FALLTHROUGH
		case 2:
			harl.complain("WARNING");
			std::cout << std::endl;
			// fall through
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}	

	return 0;
}
