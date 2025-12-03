#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade) {
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
	if (this != &other) {
		this->_grade = other._grade;
	}
	return *this;
}

std::string const &Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::incrementGrade() {
	if (this->_grade <= 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade >= 150)
		throw GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because "
				  << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}
