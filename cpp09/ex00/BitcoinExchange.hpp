#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

class BitcoinExchange {
private:
    std::map<std::string, float> data;

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