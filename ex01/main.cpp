#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <list>

int main() {

        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    
    std::cout << "\n=== Exceptions ===" << std::endl;
    {
        Span sp(3);
        try {
            sp.addNumber(1);
            sp.addNumber(2);
            sp.addNumber(3);
            sp.addNumber(4); // Should throw
        } catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        Span sp2(1);
        try {
            sp2.addNumber(42);
            sp2.shortestSpan(); // Should throw
        } catch (std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }
    
    std::cout << "\n=== 10,000 numbers ===" << std::endl;
    {
        Span sp(10000);
        std::srand(std::time(0));
        
        for (int i = 0; i < 10000; ++i) {
            sp.addNumber(std::rand() % 100000);
        }
        
        std::cout << "Shortest span (10k numbers): " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span (10k numbers): " << sp.longestSpan() << std::endl;
    }
    
    std::cout << "\n=== Range of iterators ===" << std::endl;
    {
        Span sp(10);
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        
        sp.addNumbers(vec.begin(), vec.end());
        
        std::list<int> lst;
        lst.push_back(6);
        lst.push_back(7);
        lst.push_back(8);
        lst.push_back(9);
        lst.push_back(10);
        
        sp.addNumbers(lst.begin(), lst.end());
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    
    std::cout << "\n=== 100,000 numbers with iterator range ===" << std::endl;
    {
        Span sp(100000);
        std::vector<int> largeVec;
        
        for (int i = 0; i < 100000; ++i) {
            largeVec.push_back(i * 2); // Even numbers for predictable spans
        }
        
        sp.addNumbers(largeVec.begin(), largeVec.end());
        
        std::cout << "Shortest span (100k numbers): " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span (100k numbers): " << sp.longestSpan() << std::endl;
    }
    
    return 0;
}