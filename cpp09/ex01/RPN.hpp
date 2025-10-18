/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 10:41:57 by tkul              #+#    #+#             */
/*   Updated: 2025/10/18 11:15:27 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>

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

        int evaluate(const std::string& expression);
};
#endif