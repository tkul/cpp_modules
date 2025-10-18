/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 10:41:46 by tkul              #+#    #+#             */
/*   Updated: 2025/10/18 10:41:47 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char** av) {
    if (ac != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    
    BitcoinExchange btc;
    btc.loadData("data.csv");
    btc.processInput(av[1]);
    
    return 0;
}
