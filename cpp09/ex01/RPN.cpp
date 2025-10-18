/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:15:46 by tkul              #+#    #+#             */
/*   Updated: 2025/10/18 11:15:47 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) {(void)other;}

RPN& RPN::operator=(const RPN& other) {
    (void)other;
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
            if (b == 0)
                throw std::runtime_error("Error");
            return a / b;
        default:
            throw std::runtime_error("Error");
    }
}

int RPN::evaluate(const std::string& expression) {
    if (expression.empty())
        throw std::runtime_error("Error");
    
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token) {
        if (token.length() == 1 && isOperator(token[0])) {
            if (stack.size() < 2)
                throw std::runtime_error("Error");
            
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();

            stack.push(applyOperator(a, b, token[0]));
        }
        else if (token.length() == 1 && std::isdigit(token[0]))
            stack.push(token[0] - '0');
        else
            throw std::runtime_error("Error");
    }
    
    if (stack.size() != 1)
        throw std::runtime_error("Error");
    
    return stack.top();
}