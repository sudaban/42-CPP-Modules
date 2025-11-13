#include "ScalarConverter.h"
#include <sstream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <cctype>

ScalarConverter::ScalarConverter() : input("") {}

ScalarConverter::ScalarConverter(const std::string& input) 
    : input(input), variable_type(0), char_value(0), int_value(0), float_value(0.0f), double_value(0.0)
{
    variable_type = validate_input();
    convert();
    print_output();
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
    : input(src.input), variable_type(src.variable_type), char_value(src.char_value),
      int_value(src.int_value), float_value(src.float_value), double_value(src.double_value)
{
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src)
{
    if (this != &src)
    {
        variable_type = src.variable_type;
        char_value = src.char_value;
        int_value = src.int_value;
        float_value = src.float_value;
        double_value = src.double_value;
    }
    return *this;
}

int ScalarConverter::validate_input()
{
    if (input.empty())
        throw ErrorException();
    
    if (input.length() == 1 && !isdigit(input[0]))
        return 1;
    
    if (input == "nan" || input == "nanf")
        return 4;
    if (input == "+inf" || input == "+inff" || input == "inf" || input == "inff")
        return 4;
    if (input == "-inf" || input == "-inff")
        return 4;
    
    bool hasDecimal = false;
    bool hasF = false;
    size_t start = 0;
    
    if (input[0] == '+' || input[0] == '-')
        start = 1;
    
    for (size_t i = start; i < input.length(); i++)
    {
        if (input[i] == '.')
        {
            if (hasDecimal)
                throw ErrorException();
            hasDecimal = true;
        }
        else if (input[i] == 'f' && i == input.length() - 1)
        {
            hasF = true;
        }
        else if (!isdigit(input[i]))
        {
            throw ErrorException();
        }
    }
    
    if (hasF)
        return 3;
    if (hasDecimal)
        return 4;
    return 2;
}

void ScalarConverter::convert()
{
    try
    {
        switch (variable_type)
        {
            case 1:
                from_char();
                break;
            case 2:
                from_int();
                break;
            case 3:
                from_float();
                break;
            case 4:
                from_double();
                break;
        }
    }
    catch (...)
    {
        throw ErrorException();
    }
}

void ScalarConverter::from_char()
{
    char_value = input[0];
    int_value = static_cast<int>(char_value);
    float_value = static_cast<float>(char_value);
    double_value = static_cast<double>(char_value);
}

void ScalarConverter::from_int()
{
    std::stringstream ss(input);
    long temp;
    ss >> temp;
    
    if (temp > std::numeric_limits<int>::max() || temp < std::numeric_limits<int>::min())
        throw ErrorException();
    
    int_value = static_cast<int>(temp);
    char_value = static_cast<char>(int_value);
    float_value = static_cast<float>(int_value);
    double_value = static_cast<double>(int_value);
}

void ScalarConverter::from_float()
{
    std::string floatStr = input;
    if (floatStr[floatStr.length() - 1] == 'f')
        floatStr = floatStr.substr(0, floatStr.length() - 1);
    
    std::stringstream ss(floatStr);
    ss >> float_value;
    
    if (float_value != float_value || float_value == std::numeric_limits<float>::infinity() || float_value == -std::numeric_limits<float>::infinity())
    {
        char_value = 0;
        int_value = 0;
        double_value = static_cast<double>(float_value);
        return;
    }
    
    char_value = static_cast<char>(float_value);
    int_value = static_cast<int>(float_value);
    double_value = static_cast<double>(float_value);
}

void ScalarConverter::from_double()
{
    std::stringstream ss(input);
    ss >> double_value;
    
    if (double_value != double_value || double_value == std::numeric_limits<double>::infinity() || double_value == -std::numeric_limits<double>::infinity())
    {
        char_value = 0;
        int_value = 0;
        float_value = static_cast<float>(double_value);
        return;
    }
    
    char_value = static_cast<char>(double_value);
    int_value = static_cast<int>(double_value);
    float_value = static_cast<float>(double_value);
}

void ScalarConverter::print_output() const
{
    std::cout << "char: ";
    if (float_value != float_value || float_value == std::numeric_limits<float>::infinity() || 
        float_value == -std::numeric_limits<float>::infinity() || int_value < 0 || int_value > 127)
        std::cout << "impossible";
    else if (int_value < 32 || int_value == 127)
        std::cout << "Non displayable";
    else
        std::cout << "'" << char_value << "'";
    std::cout << std::endl;
    
    std::cout << "int: ";
    if (float_value != float_value || float_value == std::numeric_limits<float>::infinity() || 
        float_value == -std::numeric_limits<float>::infinity() || 
        double_value > std::numeric_limits<int>::max() || 
        double_value < std::numeric_limits<int>::min())
        std::cout << "impossible";
    else
        std::cout << int_value;
    std::cout << std::endl;
    
    std::cout << "float: ";
    if (float_value != float_value)
        std::cout << "nanf";
    else if (float_value == std::numeric_limits<float>::infinity())
        std::cout << "+inff";
    else if (float_value == -std::numeric_limits<float>::infinity())
        std::cout << "-inff";
    else
    {
        std::cout << std::fixed << std::setprecision(1) << float_value << "f";
    }
    std::cout << std::endl;
    
    std::cout << "double: ";
    if (double_value != double_value)
        std::cout << "nan";
    else if (double_value == std::numeric_limits<double>::infinity())
        std::cout << "+inf";
    else if (double_value == -std::numeric_limits<double>::infinity())
        std::cout << "-inf";
    else
    {
        std::cout << std::fixed << std::setprecision(1) << double_value;
    }
    std::cout << std::endl;
}

std::string ScalarConverter::get_input() const
{
    return input;
}

int ScalarConverter::get_type() const
{
    return variable_type;
}

char ScalarConverter::get_char() const
{
    return char_value;
}

int ScalarConverter::get_int() const
{
    return int_value;
}

float ScalarConverter::get_float() const
{
    return float_value;
}

double ScalarConverter::get_double() const
{
    return double_value;
}

const char* ScalarConverter::ErrorException::what() const throw()
{
    return "Invalid input for scalar conversion, must be in a valid format.";
}