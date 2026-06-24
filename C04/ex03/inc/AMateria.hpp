#pragma once

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

#include "ICharacter.hpp"

class ICharacter;  // Forward declaration

class AMateria {
 protected:
  std::string type;

 public:
  AMateria();
  AMateria(std::string const& type);
  AMateria(const AMateria& copy);
  virtual ~AMateria();

  AMateria& operator=(const AMateria& rhs);

  std::string const& getType() const;  // Returns the materia type

  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);
};

#endif
