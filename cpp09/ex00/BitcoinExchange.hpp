/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 10:41:40 by tkul              #+#    #+#             */
/*   Updated: 2025/10/18 10:41:41 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

class BitcoinExchange {
private:
    std::map<std::string, float> data;
    // data["2002-02-27", 0.13]

    bool isValidDate(const std::string &date) const;
    bool isValidValue(const std::string &valueStr, float &value) const;
    std::string getPreviousDate(const std::string &date) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void loadData(const std::string &filename);
    void processInput(const std::string &filename) const;
};

#endif