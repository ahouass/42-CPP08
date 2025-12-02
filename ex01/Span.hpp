#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>
#include <iterator>
#include <iostream>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;
    
public:
    Span();
    Span(unsigned int N);
    Span(const Span& copy);
    Span& operator=(const Span& other);
    ~Span();
    
    void addNumber(int number);
    
    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end) {
        size_t distance = std::distance(begin, end);
        if (_numbers.size() + distance > _maxSize) {
            throw FullException();
        }
        _numbers.insert(_numbers.end(), begin, end);
    }
    
    int shortestSpan() const;
    int longestSpan() const;
    
    unsigned int getSize() const;
    unsigned int getMaxSize() const;
    
    class FullException : public std::exception {
		public:
			virtual const char* what() const throw();
    };
    
    class NoSpanException : public std::exception {
		public:
			virtual const char* what() const throw();
    };
};

#endif