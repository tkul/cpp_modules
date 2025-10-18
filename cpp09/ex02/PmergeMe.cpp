/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 10:42:05 by tkul              #+#    #+#             */
/*   Updated: 2025/10/18 10:42:06 by tkul             ###   ########.fr       */
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
            std::cerr << "Error" << std::endl;
            exit(1);
        }
        for (size_t j = 0; j < str.length(); j++) {
            if (!isdigit(str[j])) {
                std::cerr << "Error" << std::endl;
                exit(1);
            }
        }
        long num = atol(str.c_str());
        if (num < 0 || num > 2147483647) {
            std::cerr << "Error" << std::endl;
            exit(1);
        }
        vec.push_back(static_cast<int>(num));
        deq.push_back(static_cast<int>(num));
    }
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
    
    for (size_t i = 1; i < pending.size(); i++) {
        std::vector<int>::iterator it = arr.begin();
        while (it != arr.end() && *it < pending[i])
            ++it;
        arr.insert(it, pending[i]);
    }
    
    if (hasStraggler) {
        std::vector<int>::iterator it = arr.begin();
        while (it != arr.end() && *it < straggler)
            ++it;
        arr.insert(it, straggler);
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
    
    for (size_t i = 1; i < pending.size(); i++) {
        std::deque<int>::iterator it = arr.begin();
        while (it != arr.end() && *it < pending[i])
            ++it;
        arr.insert(it, pending[i]);
    }
    
    if (hasStraggler) {
        std::deque<int>::iterator it = arr.begin();
        while (it != arr.end() && *it < straggler)
            ++it;
        arr.insert(it, straggler);
    }
}

void PmergeMe::sortAndDisplay() {
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size() && i < 5; i++)
        std::cout << vec[i] << " ";
    if (vec.size() > 5)
        std::cout << "[...]";
    std::cout << std::endl;
    
    struct timeval start, end;
    gettimeofday(&start, NULL);
    fordJohnsonSortVector(vec);
    gettimeofday(&end, NULL);
    double timeVec = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
    
    gettimeofday(&start, NULL);
    fordJohnsonSortDeque(deq);
    gettimeofday(&end, NULL);
    double timeDeq = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
    
    std::cout << "After:  ";
    for (size_t i = 0; i < vec.size() && i < 5; i++)
        std::cout << vec[i] << " ";
    if (vec.size() > 5)
        std::cout << "[...]";
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << vec.size() 
              << " elements with std::vector : " << std::fixed 
              << std::setprecision(5) << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() 
              << " elements with std::deque  : " << std::fixed 
              << std::setprecision(5) << timeDeq << " us" << std::endl;
}
