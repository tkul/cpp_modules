#include "Base.hpp"
#include <iostream>

int main() {
    std::cout << "=== Testing generate() and identify() functions ===" << std::endl;
    
    for (int i = 0; i < 5; i++) {
        std::cout << "\n--- Test " << (i + 1) << " ---" << std::endl;
        
        Base* obj = generate();

        if (obj == NULL) {
            std::cout << "Generation failed!" << std::endl;
            continue;
        }
        
        std::cout << "identify(Base* p): ";
        identify(obj);
        
        std::cout << "identify(Base& p): ";
        identify(*obj);
        
        delete obj;
    }
    
    std::cout << "\n=== Manual testing with known types ===" << std::endl;
    
    A* a = new A();
    std::cout << "\nTesting A object:" << std::endl;
    std::cout << "Pointer: "; identify(a);
    std::cout << "Reference: "; identify(*a);

    B* b = new B();
    std::cout << "\nTesting B object:" << std::endl;
    std::cout << "Pointer: "; identify(b);
    std::cout << "Reference: "; identify(*b);

    C* c = new C();
    std::cout << "\nTesting C object:" << std::endl;
    std::cout << "Pointer: "; identify(c);
    std::cout << "Reference: "; identify(*c);
    
    delete a;
    delete b;
    delete c;
    
    return 0;
}