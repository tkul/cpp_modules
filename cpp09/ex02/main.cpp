/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 10:42:02 by tkul              #+#    #+#             */
/*   Updated: 2025/10/18 10:42:03 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    PmergeMe sorter;
    sorter.fillContainers(argv + 1, argc - 1);
    sorter.sortAndDisplay();
    
    return 0;
}
