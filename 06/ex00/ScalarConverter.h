#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>
#include <sstream>
#include <limits>
#include <iomanip>
#include <cmath>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);
    ~ScalarConverter();

    static int validate_input(const std::string& input);
    static void from_char(const std::string& input);
    static void from_int(const std::string& input);
    static void from_float(const std::string& input);
    static void from_double(const std::string& input);

public:
    static void convert(const std::string& input);

    class ErrorException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};

#endif