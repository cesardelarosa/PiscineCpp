#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: _name("Default AForm"), _isSigned(false), _signGrade(150), _executeGrade(150) {
}

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: _name(other._name), _isSigned(other._isSigned),
	  _signGrade(other._signGrade), _executeGrade(other._executeGrade) {
}

AForm::~AForm() {
}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

const std::string &AForm::getName() const {
	return this->_name;
}

bool AForm::isSigned() const {
	return this->_isSigned;
}

int AForm::getSignGrade() const {
	return this->_signGrade;
}

int AForm::getExecuteGrade() const {
	return this->_executeGrade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	this->_isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

void AForm::execute(Bureaucrat const &executor) const {
	if (!this->_isSigned)
		throw NotSignedException();
	if (executor.getGrade() > this->_executeGrade)
		throw GradeTooLowException();
	this->beExecuted();
}

const char *AForm::NotSignedException::what() const throw() {
	return "Form is not signed";
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
	os << "AForm " << form.getName()
	   << ", signed: " << (form.isSigned() ? "yes" : "no")
	   << ", sign grade: " << form.getSignGrade()
	   << ", exec grade: " << form.getExecuteGrade();
	return os;
}
