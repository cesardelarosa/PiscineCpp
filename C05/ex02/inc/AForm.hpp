#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
  public:
	AForm();
	AForm(const std::string &name, int signGrade, int executeGrade);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();

	const std::string &getName() const;
	bool isSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;

	void beSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception {
	  public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	  public:
		virtual const char *what() const throw();
	};

	void execute(Bureaucrat const &executor) const;

	class NotSignedException : public std::exception {
	  public:
		virtual const char *what() const throw();
	};

  protected:
	virtual void beExecuted() const = 0;

  private:
	const std::string _name;
	bool _isSigned;
	const int _signGrade;
	const int _executeGrade;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
