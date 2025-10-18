/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 10:42:05 by tkul              #+#    #+#             */
/*   Updated: 2025/10/18 12:36:57 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : vec(other.vec), deq(other.deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        vec = other.vec;
        deq = other.deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::fillContainers(char** input, int size) {
    for (int i = 0; i < size; i++) {
        std::string str(input[i]);
        
        if (str.empty() || str[0] == '-') {
            throw std::runtime_error("Error");
        }
        
        size_t start = 0;
        if (str[0] == '+')
            start = 1;
        
        for (size_t j = start; j < str.length(); j++) {
            if (!isdigit(str[j])) {
                throw std::runtime_error("Error");
            }
        }
        
        long num = atol(str.c_str());
        
        if (num < 0 || num > 2147483647) {
            throw std::runtime_error("Error");
        }
        
        vec.push_back(static_cast<int>(num));
        deq.push_back(static_cast<int>(num));
    }
    
    if (vec.empty()) {
        throw std::runtime_error("Error");
    }
}

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n) {
    if (n == 0)
        return std::vector<size_t>();
    
    //0, 1, 1, 3, 5, 11, 21, 43, 85...
    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    
    while (jacobsthal.back() < n * 2) {
        size_t next = jacobsthal[jacobsthal.size() - 1] + 
                      2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next);
    }
    
    std::vector<size_t> insertionOrder;
    std::vector<bool> used(n, false);
    
    for (size_t i = 2; i < jacobsthal.size() && insertionOrder.size() < n; i++) {
        size_t currentJacob = jacobsthal[i];
        size_t prevJacob = jacobsthal[i - 1];
        
        for (size_t j = std::min(currentJacob, n); j > prevJacob; j--) {
            if (!used[j - 1]) {
                insertionOrder.push_back(j - 1);
                used[j - 1] = true;
            }
        }
    }
    
    for (size_t i = 0; i < n; i++) {
        if (!used[i])
            insertionOrder.push_back(i);
    }
    
    return insertionOrder;
}

void PmergeMe::insertionSortVector(std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::insertionSortDeque(std::deque<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::fordJohnsonSortVector(std::vector<int>& arr) {
    if (arr.size() <= 10) {
        insertionSortVector(arr);
        return;
    }
    
    std::vector<std::pair<int, int> > pairs;
    bool hasStraggler = (arr.size() % 2 != 0);
    int straggler = hasStraggler ? arr.back() : 0;
    
    size_t pairCount = arr.size() / 2;
    for (size_t i = 0; i < pairCount; i++) {
        int a = arr[i * 2];
        int b = arr[i * 2 + 1];
        if (a > b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }
    
    for (size_t i = 1; i < pairs.size(); i++) {
        std::pair<int, int> key = pairs[i];
        int j = i - 1;
        while (j >= 0 && pairs[j].first > key.first) {
            pairs[j + 1] = pairs[j];
            j--;
        }
        pairs[j + 1] = key;
    }
    
    std::vector<int> mainChain;
    std::vector<int> pending;
    
    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].first);
        pending.push_back(pairs[i].second);
    }
    
    arr.clear();
    if (!pending.empty())
        arr.push_back(pending[0]);
    
    for (size_t i = 0; i < mainChain.size(); i++)
        arr.push_back(mainChain[i]);
    
    if (pending.size() > 1) {
        std::vector<size_t> insertionOrder = 
            generateJacobsthalSequence(pending.size() - 1);
        
        for (size_t i = 0; i < insertionOrder.size(); i++) {
            size_t idx = insertionOrder[i] + 1;
            if (idx < pending.size()) {
                int toInsert = pending[idx];
                
                std::vector<int>::iterator pos = 
                    std::lower_bound(arr.begin(), arr.end(), toInsert);
                arr.insert(pos, toInsert);
            }
        }
    }
    
    if (hasStraggler) {
        std::vector<int>::iterator pos = 
            std::lower_bound(arr.begin(), arr.end(), straggler);
        arr.insert(pos, straggler);
    }
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& arr) {
    if (arr.size() <= 10) {
        insertionSortDeque(arr);
        return;
    }
    
    std::deque<std::pair<int, int> > pairs;
    bool hasStraggler = (arr.size() % 2 != 0);
    int straggler = hasStraggler ? arr.back() : 0;
    
    size_t pairCount = arr.size() / 2;
    for (size_t i = 0; i < pairCount; i++) {
        int a = arr[i * 2];
        int b = arr[i * 2 + 1];
        if (a > b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }
    
    for (size_t i = 1; i < pairs.size(); i++) {
        std::pair<int, int> key = pairs[i];
        int j = i - 1;
        while (j >= 0 && pairs[j].first > key.first) {
            pairs[j + 1] = pairs[j];
            j--;
        }
        pairs[j + 1] = key;
    }
    
    std::deque<int> mainChain;
    std::deque<int> pending;
    
    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].first);
        pending.push_back(pairs[i].second);
    }
    
    arr.clear();
    if (!pending.empty())
        arr.push_back(pending[0]);
    
    for (size_t i = 0; i < mainChain.size(); i++)
        arr.push_back(mainChain[i]);
    
    if (pending.size() > 1) {
        std::vector<size_t> insertionOrder = 
            generateJacobsthalSequence(pending.size() - 1);
        
        for (size_t i = 0; i < insertionOrder.size(); i++) {
            size_t idx = insertionOrder[i] + 1;
            if (idx < pending.size()) {
                int toInsert = pending[idx];
                
                std::deque<int>::iterator pos = 
                    std::lower_bound(arr.begin(), arr.end(), toInsert);
                arr.insert(pos, toInsert);
            }
        }
    }
    
    if (hasStraggler) {
        std::deque<int>::iterator pos = 
            std::lower_bound(arr.begin(), arr.end(), straggler);
        arr.insert(pos, straggler);
    }
}

void PmergeMe::sortAndDisplay() {
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size() && i < 5; i++) {
        std::cout << vec[i];
        if (i < 4 && i < vec.size() - 1)
            std::cout << " ";
    }
    if (vec.size() > 5)
        std::cout << " [...]";
    std::cout << std::endl;
    
    struct timeval start, end;
    gettimeofday(&start, NULL);
    fordJohnsonSortVector(vec);
    gettimeofday(&end, NULL);
    double timeVec = (end.tv_sec - start.tv_sec) * 1000000.0 + 
                     (end.tv_usec - start.tv_usec);
    
    gettimeofday(&start, NULL);
    fordJohnsonSortDeque(deq);
    gettimeofday(&end, NULL);
    double timeDeq = (end.tv_sec - start.tv_sec) * 1000000.0 + 
                     (end.tv_usec - start.tv_usec);
    
    std::cout << "After:  ";
    for (size_t i = 0; i < vec.size() && i < 5; i++) {
        std::cout << vec[i];
        if (i < 4 && i < vec.size() - 1)
            std::cout << " ";
    }
    if (vec.size() > 5)
        std::cout << " [...]";
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << vec.size() 
              << " elements with std::vector : " << std::fixed 
              << std::setprecision(5) << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() 
              << " elements with std::deque  : " << std::fixed 
              << std::setprecision(5) << timeDeq << " us" << std::endl;
}