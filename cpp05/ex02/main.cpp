/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:41:20 by tkul              #+#    #+#             */
/*   Updated: 2025/10/08 12:12:42 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
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