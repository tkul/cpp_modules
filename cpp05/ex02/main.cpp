#include <iostream>
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat bob("Bob", 1);
    RobotomyRequestForm robotomy("Target1");
    ShrubberyCreationForm shrubbery("Target2");
    PresidentialPardonForm presidential("Target3");

    try {
        bob.signForm(robotomy);
        bob.executeForm(robotomy);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        bob.signForm(shrubbery);
        bob.executeForm(shrubbery);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        bob.signForm(presidential);
        bob.executeForm(presidential);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}