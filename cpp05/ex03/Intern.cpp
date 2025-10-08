#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &other) {
    (void)other;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &formType, const std::string &target) const {
    if (formType == "shrubbery creation")
        return new ShrubberyCreationForm(target);
    else if (formType == "robotomy request")
        return new RobotomyRequestForm(target);
    else if (formType == "presidential pardon")
        return new PresidentialPardonForm(target);
    else {
        std::cerr << "Error: Unknown form type " << formType << std::endl;
        return nullptr;
    }
}

