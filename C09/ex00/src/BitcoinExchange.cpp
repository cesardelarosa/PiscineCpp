#include "BitcoinExchange.hpp"
#include <stdexcept>
#include <cstdlib>
#include <cctype>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) { *this = src; }
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	(void)rhs;
	return *this;
}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string &dbPath) { (void)dbPath; }

void BitcoinExchange::processInput(const std::string &inputPath) {
	(void)inputPath;
}

bool BitcoinExchange::isValidDate(const std::string &date) const {
    // Format YYYY-MM-DD
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        throw std::invalid_argument("bad input => " + date);
    }

    // YYYY, MM & DD are numbers
    for (size_t i = 0; i < date.length(); ++i) {
        if (i == 4 || i == 7) continue;
        if (!isdigit(date[i])) {
            throw std::invalid_argument("bad input => " + date);
        }
    }

    // Get numbers data
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    // Valid year
    if (year < 2009) {
        throw std::invalid_argument("bad input => " + date);
    }

	// Valid month
    if (month < 1 || month > 12) {
        throw std::invalid_argument("bad input => " + date);
    }

	// Valid days
    int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        daysInMonth[2] = 29;
    }
    if (day < 1 || day > daysInMonth[month]) {
        throw std::invalid_argument("bad input => " + date);
    }

    return true;
}

bool BitcoinExchange::isValidValue(float value) const {
    if (value < 0) {
        throw std::invalid_argument("not a positive number.");
    }
    if (value > 1000) {
        throw std::invalid_argument("too large a number.");
    }
    
    return true;
}