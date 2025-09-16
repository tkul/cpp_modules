#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    // Intern intern;
    // Bureaucrat bureaucrat("Bureaucrat", 1);

    // AForm *form = intern.makeForm("shrubbery creation", "Garden");
    // if (form)
    // {
    //     bureaucrat.signForm(*form);
    //     bureaucrat.executeForm(*form);
    //     delete form;
    // }

    // form = intern.makeForm("robotomy request", "Target");
    // if (form)
    // {
    //     bureaucrat.signForm(*form);
    //     bureaucrat.executeForm(*form);
    //     delete form;
    // }

    // form = intern.makeForm("presidential pardon", "Target");
    // if (form)
    // {
    //     bureaucrat.signForm(*form);
    //     bureaucrat.executeForm(*form);
    //     delete form;
    // }

    Intern someRandomIntern;
    AForm *rrf;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");

    if (rrf)
    {
        Bureaucrat highGrade("Boss", 1);
        highGrade.signForm(*rrf);
        highGrade.executeForm(*rrf);
        delete rrf;
    }

    AForm *scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
    AForm *ppf = someRandomIntern.makeForm("presidential pardon", "Criminal");

    if (scf && ppf)
    {
        Bureaucrat boss("BigBoss", 1);
        boss.signForm(*scf);
        boss.executeForm(*scf);
        boss.signForm(*ppf);
        boss.executeForm(*ppf);

        delete scf;
        delete ppf;
    }

    AForm *unknown = someRandomIntern.makeForm("unknown form", "Target");
    if (!unknown)
        std::cout << "Form creation failed as expected" << std::endl;

    return 0;

    return 0;
}