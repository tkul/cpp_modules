#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Intern someRandomIntern;
    
    try {
        AForm *rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf) {
            Bureaucrat highGrade("Boss", 1);
            highGrade.signForm(*rrf);
            highGrade.executeForm(*rrf);
            delete rrf;
        }
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        AForm *scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
        if (scf) {
            Bureaucrat midGrade("Manager", 140);
            midGrade.signForm(*scf);
            midGrade.executeForm(*scf);
            delete scf;
        }
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        AForm *ppf = someRandomIntern.makeForm("presidential pardon", "Criminal");
        if (ppf) {
            Bureaucrat lowGrade("Clerk", 50);
            lowGrade.signForm(*ppf);
            lowGrade.executeForm(*ppf);
            delete ppf;
        }
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        AForm *unknown = someRandomIntern.makeForm("unknown form", "Target");
        if (!unknown) {
            std::cout << "Form creation failed as expected" << std::endl;
        }
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}