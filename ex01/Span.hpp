#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Span {

	private:
		unsigned int n;
		std::vector<int> numbers;
	public:
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;
};

#endif