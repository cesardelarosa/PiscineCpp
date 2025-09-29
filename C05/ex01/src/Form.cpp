#include "Form.hpp"

// Orthodox Canonical Form
Form::Form(const std::string &name, bool isSigned, int signGrade, int executeGrade)
    : _name(name), _isSigned(isSigned), _signGrade(validateGrade(signGrade)), _executeGrade(validateGrade(executeGrade))
{
}

Form::~Form()
{
}

Form::Form(const Form &other)
    : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
}

Form &Form::operator=(const Form &other)
{
    (void)other;
    return *this;
}

// Getters
const std::string &Form::getName() const
{
    return this->_name;
}

bool Form::isSigned() const
{
    return this->_isSigned;
}

int Form::getSignGrade() const
{
    return this->_signGrade;
}

int Form::getExecuteGrade() const
{
    return this->_executeGrade;
}

//  Exception handling
const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

int Form::validateGrade(int grade)
{
    if (grade < 1)
        throw Form::GradeTooHighException();
    if (grade > 150)
        throw Form::GradeTooLowException();
    return grade;
}

// Be signed
void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_signGrade)
        throw Form::GradeTooLowException();
    this->_isSigned = true;
}