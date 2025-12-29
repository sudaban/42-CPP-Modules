#include "MutantStack.h"
#include <list>
#include <vector>
#include <algorithm>

#define YELLOW "\033[33m"
#define RED    "\033[31m"
#define BLUE   "\033[34m"
#define RESET  "\033[0m"

void print_separator(std::string name) {
    std::cout << RED << "\n--- [ " << name << " ] ---" << RESET << std::endl;
}

int main()
{
    print_separator("SUBJECT TEST: MUTANT STACK");
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::it it = mstack.begin();
    MutantStack<int>::it ite = mstack.end();
    
    ++it;
    --it;
    while (it != ite) {
        std::cout << YELLOW << *it << RESET << " ";
        ++it;
    }
    std::cout << std::endl;

    // LIST COMPRESSION
    print_separator("COMPARISON TEST: STD::LIST");
    std::list<int> mlist;
    
    mlist.push_back(5);
    mlist.push_back(17);
    
    std::cout << "Back: " << mlist.back() << std::endl;
    mlist.pop_back();
    std::cout << "Size: " << mlist.size() << std::endl;
    
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);
    
    std::list<int>::iterator lit = mlist.begin();
    std::list<int>::iterator lite = mlist.end();
    
    ++lit;
    --lit;
    while (lit != lite) {
        std::cout << BLUE << *lit << RESET << " ";
        ++lit;
    }
    std::cout << std::endl;

    print_separator("REVERSE ITERATION");
    MutantStack<int>::rit rit = mstack.rbegin();
    MutantStack<int>::rit rite = mstack.rend();
    
    while (rit != rite) {
        std::cout << "[" << *rit << "] ";
        ++rit;
    }
    std::cout << std::endl;

    std::stack<int> s(mstack);
    std::cout << "\nStack copy created successfully. Size: " << s.size() << std::endl;

    return 0;
}