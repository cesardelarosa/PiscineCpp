#pragma once
#include <cstddef>
#include <string>

class Contact {
public:
  Contact();
  ~Contact();

  void fillFromPrompt();
  void printRow(size_t index) const;
  void printCard() const;

private:
  std::string _prompt(const std::string &prompt);

  std::string _firstName;
  std::string _lastName;
  std::string _nickName;
  std::string _phoneNumber;
  std::string _darkestSecret;
};
