#ifndef FORM_HPP
#define FORM_HPP

#pragma once
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
public:
    Form(const std::string &name, bool isSigned, int signGrade, int executeGrade);
    ~Form();
    Form(const Form &other);
    Form &operator=(const Form &other);

    const std::string &getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    void beSigned(const Bureaucrat &bureaucrat);
private:
    const std::string   _name;
    bool                _isSigned;
    const int           _signGrade;
    const int           _executeGrade;

    static int validateGrade(int grade);
};

std::ostream &operator<<(std::ostream &o, const Form &rhs);

#endif // FORM_HPP