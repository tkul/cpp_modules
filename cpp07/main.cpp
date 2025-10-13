#include <iostream>

template <typename T>
void login(T& username, T& password) {
    std::cout << "Please enter your username: ";
    std::cin >> username;
    std::cout << "Please enter your password: ";
    std::cin >> password;
    std::cout << "Welcome " << username << "!" << std::endl;
}

int main()
{
    std::string username_1;
    std::string password_1;
    
    login(username_1, password_1);

    
    int username_2;
    int password_2;

    login(username_2, password_2);

    return 0;
}
