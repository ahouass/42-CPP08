#include "Span.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::cout << "=== Testing Span class ===" << std::endl;
    
    // Test 1: Basic functionality
    std::cout << "\n--- Test 1: Basic functionality ---" << std::endl;
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Test 2: Adding too many numbers
    std::cout << "\n--- Test 2: Overflow test ---" << std::endl;
    try {
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4); // This should throw
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Test 3: Not enough numbers for span
    std::cout << "\n--- Test 3: Not enough numbers ---" << std::endl;
    try {
        Span sp(5);
        sp.addNumber(1);
        sp.shortestSpan(); // This should throw
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    try {
        Span sp(5);
        sp.longestSpan(); // This should throw
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Test 4: Large span test (10,000 numbers)
    std::cout << "\n--- Test 4: Large test (10,000 numbers) ---" << std::endl;
    try {
        Span sp(10000);
        
        // Fill with numbers from 1 to 10000
        for (int i = 1; i <= 10000; ++i) {
            sp.addNumber(i);
        }
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Test 5: Random numbers test
    std::cout << "\n--- Test 5: Random numbers test ---" << std::endl;
    try {
        Span sp(1000);
        std::srand(std::time(0));
        
        for (int i = 0; i < 1000; ++i) {
            sp.addNumber(std::rand() % 10000);
        }
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}