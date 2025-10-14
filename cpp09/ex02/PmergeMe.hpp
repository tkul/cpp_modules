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