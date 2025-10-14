#include "BitcoinExchange.hpp"
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : data(other.data) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    for (size_t i = 0; i < 10; i++)
        if (i != 4 && i != 7 && !isdigit(date[i]))
            return false;
    int y = atoi(date.substr(0, 4).c_str());
    int m = atoi(date.substr(5, 2).c_str());
    int d = atoi(date.substr(8, 2).c_str());
    if (m < 1 || m > 12 || d < 1 || d > 31)
        return false;
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        days[1] = 29;
    return d <= days[m - 1];
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value) const {
    if (valueStr.empty())
        return false;
    char* end;
    value = strtof(valueStr.c_str(), &end);
    return (*end == '\0' || *end == '\n' || *end == '\r');
}

std::string BitcoinExchange::getPreviousDate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = data.lower_bound(date);
    if (it != data.end() && it->first == date)
        return it->first;
    return (it != data.begin()) ? (--it)->first : "";
}

void BitcoinExchange::loadData(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        size_t pos = line.find(',');
        if (pos == std::string::npos)
            continue;
        float value;
        if (isValidValue(line.substr(pos + 1), value))
            data[line.substr(0, pos)] = value;
    }
    file.close();
}

void BitcoinExchange::processInput(const std::string& filename) const {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        size_t pos = line.find(" | ");
        if (pos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, pos);
        std::string valueStr = line.substr(pos + 3);
        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        float value;
        if (!isValidValue(valueStr, value)) {
            std::cerr << "Error: bad input => " << valueStr << std::endl;
            continue;
        }
        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        std::string closest = getPreviousDate(date);
        if (closest.empty()) {
            std::cerr << "Error: no data available." << std::endl;
            continue;
        }
        std::cout << date << " => " << value << " = " << value * data.find(closest)->second << std::endl;
    }
}
