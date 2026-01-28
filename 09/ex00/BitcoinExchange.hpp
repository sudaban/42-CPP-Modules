/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:08:29 by sdaban            #+#    #+#             */
/*   Updated: 2026/01/26 12:10:34 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

#define ERR_POSITIVE "Error: not a positive number."
#define ERR_LARGE    "Error: too large a number."
#define ERR_FILE    "Error: could not open file."

class BitcoinExchange
{
private:
    std::map<std::string, float> m_rates;

    bool   valid_date(const std::string &date);
    bool   valid_value(const std::string &value);
    float  to_float(const std::string &s);
    std::string trim(const std::string &s);
    float  get_rate_for_date(const std::string &date);

public:
    BitcoinExchange() {}
    ~BitcoinExchange() {}
    bool load_database(const std::string &file);
    void process_input(const std::string &file);
};

#endif // BITCOINEXCHANGE_HPP
