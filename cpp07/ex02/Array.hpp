#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template <typename T>
class Array {
private:
    T *array;
    unsigned int n;

public:
    Array() : array(new T[0]), n(0) {}
    
    Array(unsigned int n) : array(new T[n]), n(n) {}
    
    Array(const Array &other) : array(new T[other.n]), n(other.n) {
        for (unsigned int i = 0; i < n; i++)
            array[i] = other.array[i];
    }
    
    Array &operator=(const Array &other) {
        if (this != &other) {
            delete[] array;
            n = other.n;
            array = new T[n];
            for (unsigned int i = 0; i < n; i++)
                array[i] = other.array[i];
        }
        return *this;
    }
    
    ~Array() { delete[] array; }

    T &operator[](unsigned int index) {
        if (index >= n)
            throw std::out_of_range("Index out of range");
        return array[index];
    }
    
    const T &operator[](unsigned int index) const {
        if (index >= n)
            throw std::out_of_range("Index out of range");
        return array[index];
    }
    
    unsigned int size() const { return n; }
};

#endif