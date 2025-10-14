#include "easyfind.hpp"

static void printTitle(const std::string &title) {
	std::cout << "\n==== " << title << " ====\n";
}

int main() {
    printTitle("Testing easyfind with std::vector");
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.pop_back();

    std::cout << "Vector contents: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found value 3 in vector at position: " << std::distance(vec.begin(), it) << std::endl;
    } catch (const NotFoundException& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    try {
        std::vector<int>::iterator it = easyfind(vec, 10);
        std::cout << "Found value 10 in vector at position: " << std::distance(vec.begin(), it) << std::endl;
    } catch (const NotFoundException& e) {
        std::cout << "Exception caught for value 10: " << e.what() << std::endl;
    }

    printTitle("Testing easyfind with std::list");

    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_front(0);

    std::cout << "List contents: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    try {
        easyfind(lst, 20);
        std::cout << "Found value 20 in list" << std::endl;
    } catch (const NotFoundException& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    try {
        easyfind(lst, 100);
        std::cout << "Found value 100 in list" << std::endl;
    } catch (const NotFoundException& e) {
        std::cout << "Exception caught for value 100: " << e.what() << std::endl;
    }

    printTitle("Testing easyfind with std::deque");

    std::deque<int> deq;
    deq.push_back(7);
    deq.push_back(14);
    deq.push_back(21);
    deq.push_back(28);
    deq.push_front(0);

    std::cout << "Deque contents: ";
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    try {
        std::deque<int>::iterator it = easyfind(deq, 14);
        std::cout << "Found value 14 in deque at position: " << std::distance(deq.begin(), it) << std::endl;
    } catch (const NotFoundException& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    try {
        easyfind(deq, 99);
        std::cout << "Found value 99 in deque" << std::endl;
    } catch (const NotFoundException& e) {
        std::cout << "Exception caught for value 99: " << e.what() << std::endl;
    }

    printTitle("Testing with empty container");

    std::vector<int> empty_vec;
    std::cout << "Empty vector contents: ";
    for (size_t i = 0; i < empty_vec.size(); ++i) {
        std::cout << empty_vec[i] << " ";
    }
    std::cout << std::endl;

    try {
        easyfind(empty_vec, 1);
        std::cout << "Found value 1 in empty vector" << std::endl;
    } catch (const NotFoundException& e) {
        std::cout << "Exception caught for empty vector: " << e.what() << std::endl;
    }
    
    return 0;
}