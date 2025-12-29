#ifndef EASYFIND_H
#define EASYFIND_H

#include <algorithm>
#include <exception>

class NotFoundException : public std::exception 
{
    const char* what() const throw() { return "No element found"; }
};

template <typename T>
typename T::iterator easyfind(T& source, int target) {
    typename T::iterator it = std::find(source.begin(), source.end(), target);
    
    if (it == source.end()) {
        throw NotFoundException();
    }
    return it;
}


#endif //EASYFIND_H