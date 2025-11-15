#include "Data.h"

Data::Data() : int_value(0), double_value(0.0), string_value(""), char_value('\0') {}

Data::Data(int int_val, double double_val, const std::string& string_val, char char_val)
	: int_value(int_val), double_value(double_val), string_value(string_val), char_value(char_val)
{}

Data::Data(const Data& other)
	: int_value(other.int_value), double_value(other.double_value), 
	  string_value(other.string_value), char_value(other.char_value)
{}

Data& Data::operator=(const Data& other) 
{
	if (this != &other) {
		this->int_value = other.int_value;
		this->double_value = other.double_value;
		this->string_value = other.string_value;
		this->char_value = other.char_value;
	}
	return *this;
}

Data::~Data() {}
