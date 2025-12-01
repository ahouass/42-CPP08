#include "easyfind.hpp"

#include <vector>
#include <list>
#include <deque>
#include <set>
#include <iostream>

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    try {
        easyfind(vec, 3);
        std::cout << "Value found in container" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);
    try {
        easyfind(lst, 20);
        std::cout << "Value found in container" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::deque<int> deq;
    deq.push_back(400);
    deq.push_back(500);
    deq.push_back(600);
    try {
        easyfind(deq, 500);
        std::cout << "Value found in container" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::set<int> st;
    st.insert(1000);
    st.insert(2000);
    st.insert(3000);
    try {
        easyfind(st, 3000);
        std::cout << "Value found in container" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}