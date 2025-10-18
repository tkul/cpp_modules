#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <stack>

class RPN {
    private:
        std::stack<int> stack;
        
        bool isOperator(char c) const;
        int applyOperator(int a, int b, char op) const;
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        void evaluate(const std::string& expression);
};
#endif