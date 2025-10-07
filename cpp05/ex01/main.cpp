#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat alice("Alice", 140);
        Form contract("Contract", 50, 100);
        alice.signForm(contract);
        std::cout << contract << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat brad("Brad", 49);
        Form contract2("Contract", 50, 100);
        brad.signForm(contract2);
        std::cout << contract2 << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}