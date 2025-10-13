/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:14:24 by tkul              #+#    #+#             */
/*   Updated: 2025/10/13 17:14:25 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"

int main( void ) {
int a = 2;
int b = 3;
::swap( a, b );

std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);

std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

return 0;
}