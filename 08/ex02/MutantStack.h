#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type::iterator it;
    typedef typename std::stack<T>::container_type::const_iterator cit;
    typedef typename std::stack<T>::container_type::reverse_iterator rit;
    typedef typename std::stack<T>::container_type::const_reverse_iterator crit;

    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack& src) : std::stack<T>(src) {}
    virtual ~MutantStack() {}
    
    MutantStack& operator=(const MutantStack& rhs) {
        if (this != &rhs)
            std::stack<T>::operator=(rhs);
        return *this;
    }

    it begin() { return this->c.begin(); }
    it end() { return this->c.end(); }
    
    cit begin() const { return this->c.begin(); }
    cit end() const { return this->c.end(); }

    rit rbegin() { return this->c.rbegin(); }
    rit rend() { return this->c.rend(); }

    crit rbegin() const { return this->c.rbegin(); }
    crit rend() const { return this->c.rend(); }
};

#endif