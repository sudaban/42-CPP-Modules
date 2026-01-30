#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        this->m_rates = other.m_rates;
    }
    return *this;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    operator=(other);
}

std::string BitcoinExchange::trim(const std::string &s)
{
    size_t start = s.find_first_not_of(" \t\n\r");
    size_t end = s.find_last_not_of(" \t\n\r");
    if (start == std::string::npos)
        return "";
    return s.substr(start, end - start + 1);
}

float BitcoinExchange::to_float(const std::string &s)
{
    return static_cast<float>(std::atof(s.c_str()));
}

bool BitcoinExchange::valid_date(const std::string &date)
{
    if (date.size() != 10)
        return false;

    for (size_t i = 0; i < date.size(); i++)
    {
        if (i == 4 || i == 7)
        {
            if (date[i] != '-')
                return false;
        }
        else if (!isdigit(date[i]))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1 || day > 31 || year < 2009)
        return false;

    return true;
}

bool BitcoinExchange::valid_value(const std::string &value)
{
    if (value.empty())
        return false;

    for (size_t i = 0; i < value.size(); i++)
    {
        if (!std::isdigit(value[i]) && value[i] != '.')
            return false;
    }

    float v = to_float(value);

    if (v < 0 || v > 1000) {
        std::cout << (v < 0 ?  ERR_POSITIVE : ERR_LARGE) << std::endl;
        return false;
    }

    return true;
}

bool BitcoinExchange::load_database(const std::string &file)
{
    std::ifstream ifs(file.c_str());
    if (!ifs.is_open())
        return false;

    std::string line;

    if (!std::getline(ifs, line))
        return false;

    while (std::getline(ifs, line))
    {
        if (line.empty())
            continue;

        size_t pos = line.find(',');

        if (pos == std::string::npos)
            continue;

        std::string date = trim(line.substr(0, pos));
        std::string value = trim(line.substr(pos + 1));

        if (!valid_date(date))
            continue;

        m_rates[date] = to_float(value);
    }

    return true;
}


float BitcoinExchange::get_rate_for_date(const std::string &date)
{
    std::map<std::string, float>::iterator it = m_rates.lower_bound(date);

    if (it == m_rates.end())
    {
        --it;
        return it->second;
    }

    if (it->first == date)
        return it->second;

    if (it == m_rates.begin())
        return it->second;

    --it;
    return it->second;
}

void BitcoinExchange::process_input(const std::string &file)
{
    std::ifstream ifs(file.c_str());

    if (!ifs.is_open())
    {
        std::cout << ERR_FILE << std::endl;
        return;
    }

    std::string line;
    std::getline(ifs, line);

    while (std::getline(ifs, line))
    {
        if (line.empty())
            continue;

        size_t pos = line.find('|');

        if (pos == std::string::npos)
        {
            std::cout << "Error: bad input 1 => " << line << std::endl;
            continue;
        }
		std::string date = trim(line.substr(0, pos));
		std::string value = trim(line.substr(pos + 1));

		if (date.empty() || value.empty())
		{
			std::cout << "Error: bad input 2 => " << line << std::endl;
			continue;
		}

        if (!valid_date(date))
        {
            std::cout << "Error: bad input 3 => " << date << std::endl;
            continue;
        }

        if (!valid_value(value))
            continue;

        float v = to_float(value);
        float rate = get_rate_for_date(date);

        std::cout << date << " => " << v << " = " << v * rate << std::endl;
    }
}
