#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>

// Orthodox Canonical Form

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) { *this = src; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	if (this != &rhs) {
		this->localData = rhs.localData;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// Database Loading

void BitcoinExchange::loadDatabase(const std::string &dbPath) {
	std::ifstream file(dbPath.c_str());
	if (!file.is_open()) {
		throw std::invalid_argument("could not open database file.");
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line)) {
		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos) {
			continue;
		}

		std::string date = line.substr(0, commaPos);
		float value = std::atof(line.substr(commaPos + 1).c_str());

		if (isValidDate(date) && value >= 0) {
			localData[date] = value;
		}
	}

	file.close();
}

// Input Processing

void BitcoinExchange::processInput(const std::string &inputPath) {
	std::ifstream file(inputPath.c_str());
	if (!file.is_open()) {
		throw std::invalid_argument("could not open file.");
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line)) {
		size_t pipePos = line.find('|');
		if (pipePos == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, pipePos);
		size_t dateEnd = date.find_last_not_of(" \t");
		if (dateEnd != std::string::npos) {
			date = date.substr(0, dateEnd + 1);
		}

		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		float value = std::atof(line.substr(pipePos + 1).c_str());

		if (value < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}

		if (value > MAX_VALUE) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		std::map<std::string, float>::iterator it = localData.lower_bound(date);

		if (it == localData.end() || it->first != date) {
			if (it == localData.begin()) {
				std::cerr << "Error: date out of database range => " << date
						  << std::endl;
				continue;
			}
			--it;
		}

		std::cout << date << " => " << value << " = " << (value * it->second)
				  << std::endl;
	}

	file.close();
}

// Validation Utils

bool BitcoinExchange::isValidDate(const std::string &date) const {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
		return false;
	}

	for (size_t i = 0; i < date.length(); ++i) {
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i])) {
			return false;
		}
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 2009) {
		return false;
	}

	if (month < 1 || month > 12) {
		return false;
	}

	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		daysInMonth[2] = 29;
	}

	if (day < 1 || day > daysInMonth[month]) {
		return false;
	}

	return true;
}

bool BitcoinExchange::isValidValue(float value) const {
	if (value < 0 || value > MAX_VALUE) {
		return false;
	}
	return true;
}
