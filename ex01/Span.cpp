#include "Span.hpp"

Span::Span(unsigned int n) : n(n) {}

Span::Span(const Span& other) : n(other.n), numbers(other.numbers) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        n = other.n;
        numbers = other.numbers;
    }
    return *this;
}

Span::~Span() {}
void Span::addNumber(int number) {
    if (numbers.size() >= n) {
        throw std::out_of_range("Cannot add more numbers, capacity reached.");
    }
    numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span.");
    }

    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int minSpan = std::numeric_limits<int>::max();
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
        throw std::logic_error("Not enough numbers to find a span.");
    }

    int minNumber = *std::min_element(numbers.begin(), numbers.end());
    int maxNumber = *std::max_element(numbers.begin(), numbers.end());

    return maxNumber - minNumber;
}

