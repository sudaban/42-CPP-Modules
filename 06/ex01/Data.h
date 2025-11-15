#ifndef DATA_H
#define DATA_H

#include <string>

struct Data {
	int			int_value;
	double		double_value;
	std::string	string_value;
	char		char_value;

	Data();
	Data(int int_val, double double_val, const std::string& string_val, char char_val);
	Data(const Data& other);
	Data& operator=(const Data& other);
	~Data();
};

#endif
