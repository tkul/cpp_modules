#include <iostream>

template <typename T>
T add(T& a, T& b) {
    return a + b;
}

int main() {
    int x = 3, y = 3;
    double p= 3.2, q = 3.2;

    std::cout << "sum of int " << add(x, y) << std::endl;
    std::cout << "sum of double " << add(p, q) << std::
endl;    return 0;
}