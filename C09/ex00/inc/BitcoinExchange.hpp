#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
  public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);
	~BitcoinExchange();

	void loadDatabase(const std::string &dbPath);
	void processInput(const std::string &inputPath);

  private:
	bool isValidDate(const std::string &date) const;
	bool isValidValue(float value) const;

	std::map<std::string, float> localData;
	static const int MAX_VALUE = 1000;
};

#endif
