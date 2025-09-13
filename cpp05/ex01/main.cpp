#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Form taxForm("Tax Form", 1, 50);
        Form bob("Bob", 2, 151);
        
        std::cout << taxForm << std::endl;
        std::cout << bob << std::endl;
        
    }
    catch (const std::exception& e)
    {
        std::cout << "ı am here" << std::endl;
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    try {
        Bureaucrat john("John", 151);
        std::cout << john << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "ı am here 2" << std::endl;
        std::cerr << "Exception: " << e.what() << std::endl;
    }


    return 0;
}