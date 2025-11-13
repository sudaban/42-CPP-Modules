#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>
#include <string>

class ScalarConverter
{
private:
	const std::string	input;
	int					variable_type;
	char				char_value;
	int					int_value;
	float				float_value;
	double				double_value;

	ScalarConverter(); // ScalarConverter sc blocked
	
	int  validate_input();
	void convert();

	void from_char();
	void from_int();
	void from_float();
	void from_double();

	void print_output() const;

	std::string get_input() const;
	int         get_type() const;
	char        get_char() const;
	int         get_int() const;
	float       get_float() const;
	double      get_double() const;

public:
	ScalarConverter(const std::string& input);
	ScalarConverter(const ScalarConverter& src);
	~ScalarConverter();

	ScalarConverter& operator=(const ScalarConverter& src);

	class ErrorException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};


#endif