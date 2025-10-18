/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 10:41:52 by tkul              #+#    #+#             */
/*   Updated: 2025/10/18 10:55:40 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char** av) {
    if (ac != 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    try {
        RPN rpn;
        int result = rpn.evaluate(av[1]);
        std::cout << result << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    return 0;
}
