#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
  for (int i = 0; i < 4; i++) templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy) {
  for (int i = 0; i < 4; i++) {
    if (copy.templates[i])
      templates[i] = copy.templates[i]->clone();
    else
      templates[i] = NULL;
  }
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < 4; i++) {
    if (templates[i]) delete templates[i];
  }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
  if (this != &rhs) {
    for (int i = 0; i < 4; i++) {
      if (templates[i]) delete templates[i];
      if (rhs.templates[i])
        templates[i] = rhs.templates[i]->clone();
      else
        templates[i] = NULL;
    }
  }
  return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
  if (!m) return;
  for (int i = 0; i < 4; i++) {
    if (templates[i] == NULL) {
      templates[i] = m;
      return;
    }
  }
  delete m;  // Prevent leak if full
}

AMateria* MateriaSource::createMateria(std::string const& type) {
  for (int i = 0; i < 4; i++) {
    if (templates[i] && templates[i]->getType() == type) {
      return templates[i]->clone();
    }
  }
  return NULL;
}
