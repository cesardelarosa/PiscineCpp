#include "Bureaucrat.hpp"
#include <iostream>

// Orthodox Canonical Form
// Constructor, Destructor, Copy Constructor, Assignment Operator
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    (void)other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    (void)other;
    return *this;
}

// Getters
const std::string &Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

// Grade modification
void Bureaucrat::incrementGrade()
{
    this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    this->_grade++;
}

// Exception handling

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

// Operator insertion
std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs){
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
    return o;
}