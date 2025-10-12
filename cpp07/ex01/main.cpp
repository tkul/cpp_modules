#include "Iter.hpp"

void printInt(int &n) {
    std::cout << n << " ";
}

void printFloat(float &f) {
    std::cout << f << " ";
}

void printChar(char &c) {
    std::cout << c << " ";
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    char charArray[] = {'H', 'e', 'l', 'l', 'o'};

    std::cout << "Integer array: ";
    iter(intArray, 5, printInt);
    std::cout << std::endl;

    std::cout << "Float array: ";
    iter(floatArray, 5, printFloat);
    std::cout << std::endl;

    std::cout << "Char array: ";
    iter(charArray, 5, printChar);
    std::cout << std::endl;

    return 0;
}