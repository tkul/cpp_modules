/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkul <tkul@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:16:04 by tkul              #+#    #+#             */
/*   Updated: 2025/10/13 17:30:03 by tkul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, size_t length, void (*f)(T &)) {
    if (!array || length == 0 || !f)
        return;
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

template <typename T>
void iter(const T *array, size_t length, void (*f)(const T &)) {
    if (!array || length == 0 || !f)
        return;
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

#endif