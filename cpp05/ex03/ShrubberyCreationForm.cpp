#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation", 145, 137), target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!getIsSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();

    std::ofstream ofs(target + "_shrubbery");
    if (!ofs)
    {
        std::cerr << "Error: Could not open file " << target + "_shrubbery" << std::endl;
        return;
    }

    ofs << "       _-_\n"
           "    /~~   ~~\\\n"
           " /~~         ~~\\\n"
           "{               }\n"
           " \\  _-     -_  /\n"
           "   ~  \\\\ //  ~\n"
           "_- -   | | _- _\n"
           "  _ -  | |   -_\n"
           "      // \\\\\n";
    ofs.close();
}