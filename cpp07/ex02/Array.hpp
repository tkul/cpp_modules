#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <stdexcept>

template <typename T>
class Array {
private:
    T* elements;
    unsigned int arraySize;

public:
    Array() : elements(NULL), arraySize(0) {}

    Array(unsigned int n) : elements(NULL), arraySize(n) {
        if (n > 0) {
            elements = new T[n]();
        }
    }

    Array(const Array& other) : elements(NULL), arraySize(other.arraySize) {
        if (arraySize > 0) {
            elements = new T[arraySize];
            for (unsigned int i = 0; i < arraySize; i++) {
                elements[i] = other.elements[i];
            }
        }
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            if (elements != NULL) {
                delete[] elements;
            }
            arraySize = other.arraySize;
            if (arraySize > 0) {
                elements = new T[arraySize];
                for (unsigned int i = 0; i < arraySize; i++) {
                    elements[i] = other.elements[i];
                }
            } else {
                elements = NULL;
            }
        }
        return *this;
    }

    ~Array() {
        if (elements != NULL) {
            delete[] elements;
        }
    }

    T& operator[](unsigned int index) {
        if (index >= arraySize) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }

    const T& operator[](unsigned int index) const {
        if (index >= arraySize) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }

    unsigned int size() const {
        return arraySize;
    }
};

#endif