#ifndef HARL_H
#define HARL_H

#include <string>

class Harl 
{
	private:
		void debug() ;
		void info();
		void warning();
		void error();
	public:
		Harl();
		~Harl();
		void complain(std::string level);

};
#endif