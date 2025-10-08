/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:41:33 by tkul              #+#    #+#             */
/*   Updated: 2025/10/08 11:55:51 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    if (!getIsSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();

    std::string filename = this->target + "_shrubbery";
    std::ofstream file(filename.c_str());
    
    if (!file.is_open()) {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return;
    }
    
        file << "         &&& &&  & &&" << std::endl;
        file << "     && &/\\&\\|& ()|/ @, &&" << std::endl;
        file << "     &/\\(/&/&||/& /_/)_&/_&" << std::endl;
        file << "  &() &/\\&|()|/&/\\ '%\" & ()" << std::endl;
        file << " &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
        file << "&&   && & &| &| /& & % ()& /&&" << std::endl;
        file << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
        file << "     &&     \\|||" << std::endl;
        file << "             |||" << std::endl;
        file << "             |||" << std::endl;
        file << "             |||" << std::endl;
        file << "       , -=-~  .-^- _" << std::endl;

    file.close();

    std::cout << "Shrubbery created in file: " << filename << std::endl;
}