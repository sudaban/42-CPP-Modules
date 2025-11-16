#include "ScalarConverter.h"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }

const char* ScalarConverter::ErrorException::what() const throw()
{
    return "Invalid input for scalar conversion, must be in a valid format.";
}

int ScalarConverter::validate_input(const std::string& input)
{
    if (input.empty())
        throw ErrorException();

    // CHAR literal: single non-digit character
    if (input.length() == 1 && !isdigit(input[0]))
        return 1; // char

    // FLOAT pseudo literals
    if (input == "nanf" || input == "+inff" || input == "-inff")
        return 3; // float

    // DOUBLE pseudo literals
    if (input == "nan" || input == "+inf" || input == "-inf")
        return 4; // double

    bool hasDecimal = false;
    bool hasF = false;
    size_t start = 0;

    if (input[0] == '+' || input[0] == '-')
        start = 1;

    for (size_t i = start; i < input.length(); i++)
    {
        if (input[i] == '.')
        {
            if (hasDecimal) throw ErrorException();
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
        return 3; // float
    if (hasDecimal)
        return 4; // double

    return 2; // int
}

void ScalarConverter::from_char(const std::string& input)
{
    char c = input[0];

    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);

    // char
    std::cout << "char: '" << c << "'" << std::endl;

    // int
    std::cout << "int: " << i << std::endl;

    // float
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

    // double
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::from_int(const std::string& input)
{
    long temp;
    std::stringstream ss(input);
    ss >> temp;

    if (temp > std::numeric_limits<int>::max() || temp < std::numeric_limits<int>::min())
        throw ErrorException();

    int i = static_cast<int>(temp);
    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);

    // char
    std::cout << "char: ";
    if (i < 32 || i == 127)
        std::cout << "Non displayable";
    else if (i < 0 || i > 127)
        std::cout << "impossible";
    else
        std::cout << "'" << c << "'";
    std::cout << std::endl;

    // int
    std::cout << "int: " << i << std::endl;

    // float
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

    // double
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::from_float(const std::string& input)
{
    std::string clean = input;
    if (clean[clean.length() - 1] == 'f')
        clean = clean.substr(0, clean.length() - 1);

    float f;
    std::stringstream ss(clean);
    ss >> f;

    double d = static_cast<double>(f);

    bool is_nan = std::isnan(f);
    bool is_inf = std::isinf(f);

    std::cout << "char: ";
    if (is_nan || is_inf || f < 0 || f > 127)
        std::cout << "impossible";
    else if (static_cast<int>(f) < 32 || static_cast<int>(f) == 127)
        std::cout << "Non displayable";
    else
        std::cout << "'" << static_cast<char>(f) << "'";
    std::cout << std::endl;

    std::cout << "int: ";
    if (is_nan || is_inf || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(f);
    std::cout << std::endl;

    std::cout << "float: ";
    if (is_nan)
        std::cout << "nanf";
    else if (f == std::numeric_limits<float>::infinity())
        std::cout << "+inff";
    else if (f == -std::numeric_limits<float>::infinity())
        std::cout << "-inff";
    else
        std::cout << std::fixed << std::setprecision(1) << f << "f";
    std::cout << std::endl;

    std::cout << "double: ";
    if (is_nan)
        std::cout << "nan";
    else if (d == std::numeric_limits<double>::infinity())
        std::cout << "+inf";
    else if (d == -std::numeric_limits<double>::infinity())
        std::cout << "-inf";
    else
        std::cout << std::fixed << std::setprecision(1) << d;
    std::cout << std::endl;
}

void ScalarConverter::from_double(const std::string& input)
{
    double d;
    std::stringstream ss(input);
    ss >> d;

    float f = static_cast<float>(d);

    bool is_nan = std::isnan(d);
    bool is_inf = std::isinf(d);

    std::cout << "char: ";
    if (is_nan || is_inf || d < 0 || d > 127)
        std::cout << "impossible";
    else if (static_cast<int>(d) < 32 || static_cast<int>(d) == 127)
        std::cout << "Non displayable";
    else
        std::cout << "'" << static_cast<char>(d) << "'";
    std::cout << std::endl;

    std::cout << "int: ";
    if (is_nan || is_inf || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(d);
    std::cout << std::endl;

    std::cout << "float: ";
    if (is_nan)
        std::cout << "nanf";
    else if (f == std::numeric_limits<float>::infinity())
        std::cout << "+inff";
    else if (f == -std::numeric_limits<float>::infinity())
        std::cout << "-inff";
    else
        std::cout << std::fixed << std::setprecision(1) << f << "f";
    std::cout << std::endl;

    std::cout << "double: ";
    if (is_nan)
        std::cout << "nan";
    else if (d == std::numeric_limits<double>::infinity())
        std::cout << "+inf";
    else if (d == -std::numeric_limits<double>::infinity())
        std::cout << "-inf";
    else
        std::cout << std::fixed << std::setprecision(1) << d;
    std::cout << std::endl;
}

void ScalarConverter::convert(const std::string& input)
{
    int type = validate_input(input);

    switch (type)
    {
        case 1: from_char(input); break;
        case 2: from_int(input); break;
        case 3: from_float(input); break;
        case 4: from_double(input); break;
        default: throw ErrorException();
    }
}