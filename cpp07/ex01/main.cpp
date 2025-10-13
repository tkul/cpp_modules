/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:16:07 by tkul              #+#    #+#             */
/*   Updated: 2025/10/13 17:57:43 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void printConstInt(const int &n) {
    std::cout << n << " ";
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    char charArray[] = {'H', 'e', 'l', 'l', 'o'};
    const int constIntArray[] = {6, 7, 8, 9, 10};

    std::cout << "Integer array: ";
    iter(intArray, 5, printInt);
    std::cout << std::endl;

    std::cout << "Float array: ";
    iter(floatArray, 5, printFloat);
    std::cout << std::endl;

    std::cout << "Char array: ";
    iter(charArray, 5, printChar);
    std::cout << std::endl;

    std::cout << "Const Integer array: ";
    iter(constIntArray, 5, printConstInt);
    std::cout << std::endl;

    return 0;
}