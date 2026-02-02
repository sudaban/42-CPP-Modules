#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <limits>

#define ERR_INVALID_INPUT "Error: invalid input"
#define ERR_NOT_POSITIVE_INT "Error: argument is not a positive integer"
#define ERR_NUMBER_TOO_LARGE "Error: number exceeds integer maximum value"
#define ERR_EMPTY_SEQUENCE "Error: empty sequence"

class PmergeMe
{
private:
    std::vector<int> m_vector;
    std::list<int> m_list;
    double m_vector_time;
    double m_list_time;

    bool is_valid_number(const std::string& str) const;
    void parse_input(int argc, char** argv);
    
    void sort_vector();
    void sort_list();
    
    size_t get_jacobsthal_number(size_t n) const;
    std::vector<size_t> generate_jacobsthal_sequence(size_t len) const;
    
    void ford_johnson_sort_vector(std::vector<int>& arr);
    void ford_johnson_sort_list(std::list<int>& arr);
    
    int binary_search_vector(const std::vector<int>& arr, int value, int left, int right) const;
    
    void print_before() const;
    void print_after() const;
    void print_times() const;

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    
    void run(int argc, char** argv);
};

#endif