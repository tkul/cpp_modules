#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();

    AForm *makeForm(const std::string &formType, const std::string &target) const;
};

#endif