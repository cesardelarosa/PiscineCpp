#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    // Nice test
    try
    {
        Bureaucrat alice("Alice", 50);
        std::cout << alice << std::endl;
        alice.incrementGrade();
        std::cout << "Post-incrementation: "<< alice << std::endl;
        alice.decrementGrade();
        std::cout << "Post-decrementation: "<< alice << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    // Test for exceptions
    try
    {
        Bureaucrat bob("Bob", 0);
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
    try
    {
        Bureaucrat charlie("Charlie", 151);
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
    return 0;
}