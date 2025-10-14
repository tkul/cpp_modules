#include "RPN.hpp"
#include <sstream>
#include <cstdlib>

RPN::RPN() {}

RPN::RPN(const RPN& other) : stack(other.stack) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other)
        stack = other.stack;
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(char c) const {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::applyOperator(int a, int b, char op) const {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                std::cerr << "Error: division by zero" << std::endl;
                exit(1);
            }
            return a / b;
        default: return 0;
    }
}

void RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token) {
        if (token.length() == 1 && isOperator(token[0])) {
            if (stack.size() < 2) {
                std::cerr << "Error" << std::endl;
                return;
            }
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            stack.push(applyOperator(a, b, token[0]));
        } else if (token.length() == 1 && isdigit(token[0])) {
            stack.push(token[0] - '0');
        } else {
            std::cerr << "Error" << std::endl;
            return;
        }
    }
    
    if (stack.size() != 1) {
        std::cerr << "Error" << std::endl;
        return;
    }
    
    std::cout << stack.top() << std::endl;
}
