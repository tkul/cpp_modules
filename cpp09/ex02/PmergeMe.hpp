/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 10:42:10 by tkul              #+#    #+#             */
/*   Updated: 2025/10/18 10:42:11 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <cstdlib>
#include <sys/time.h>
#include <iomanip>

class PmergeMe {
    private:
        std::vector<int> vec;
        std::deque<int> deq;

        void fordJohnsonSortVector(std::vector<int>& arr);
        void fordJohnsonSortDeque(std::deque<int>& arr);
        void insertionSortVector(std::vector<int>& arr);
        void insertionSortDeque(std::deque<int>& arr);
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void fillContainers(char** input, int size);
        void sortAndDisplay();
};
#endif