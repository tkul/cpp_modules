#include "Span.hpp"

Span::Span(unsigned int n) : maxSize(n) {}
Span::Span(const Span& other) : maxSize(other.maxSize), numbers(other.numbers) {}
Span& Span::operator=(const Span& other) {
    if (this != &other) {
        maxSize = other.maxSize;
        numbers = other.numbers;
    }
    return *this;
}
Span::~Span() {}

void Span::addNumber(int number) {
    if (numbers.size() >= maxSize) {
        throw std::overflow_error("Cannot add more numbers, span is full");
    }
    numbers.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (numbers.size() + std::distance(begin, end) > maxSize) {
        throw std::overflow_error("Cannot add more numbers, span will exceed its maximum size");
    }
    numbers.insert(numbers.end(), begin, end);
}

int Span::shortestSpan() const {
    if (numbers.size() < 2) {
        throw std::underflow_error("Not enough numbers to find a span");
    }
    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    int minSpan = INT_MAX;
    for (size_t i = 1; i < sortedNumbers.size(); ++i) {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (numbers.size() < 2) {
        throw std::underflow_error("Not enough numbers to find a span");
    }
    int minNumber = *std::min_element(numbers.begin(), numbers.end());
    int maxNumber = *std::max_element(numbers.begin(), numbers.end());
    return maxNumber - minNumber;
}

