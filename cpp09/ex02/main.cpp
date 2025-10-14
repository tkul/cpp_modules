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
