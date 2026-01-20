#include "PmergeMe.h"
#include <cstdlib>
#include <stdexcept>
#include <limits>

PmergeMe::PmergeMe() : m_vector_time(0), m_list_time(0) {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    operator=(other);
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other) {
        m_vector = other.m_vector;
        m_list = other.m_list;
        m_vector_time = other.m_vector_time;
        m_list_time = other.m_list_time;
    }
    return *this;
}


bool PmergeMe::is_valid_number(const std::string &str)
{
    if (str.empty())
        return false;
    
    for (size_t i = 0; i < str.length(); i++) {
        if (!isdigit(str[i]))
            return false;
    }
    
    std::istringstream iss(str);
    long num;
    iss >> num;
    
    if (num < 0 || num > std::numeric_limits<int>::max())
        return false;
    
    return true;
}

void PmergeMe::parse_input(int argc, char **argv)
{
    for (int i = 1; i < argc; i++) {
        std::string arg(argv[i]);
        
        if (!is_valid_number(arg))
            throw std::runtime_error(ERR_INVALID_ARG + arg);
        
        int num = atoi(arg.c_str());
        m_vector.push_back(num);
        m_list.push_back(num);
    }
    
    if (m_vector.empty())
        throw std::runtime_error(ERR_EMPTY_VECTOR);
}

void PmergeMe::insertion_sort_vector(std::vector<int> &arr, int left, int right)
{
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::insertion_sort_list(std::list<int> &arr)
{
    if (arr.size() <= 1)
        return;
    
    std::list<int>::iterator i = arr.begin();
    ++i;
    
    while (i != arr.end()) {
        int key = *i;
        std::list<int>::iterator j = i;
        std::list<int>::iterator prev = i;
        --prev;
        
        while (j != arr.begin() && *prev > key) {
            *j = *prev;
            --j;
            if (j != arr.begin())
                --prev;
        }
        *j = key;
        ++i;
    }
}

std::vector<int> PmergeMe::merge_vector(std::vector<int> &left, std::vector<int> &right)
{
    std::vector<int> result;
    size_t i = 0, j = 0;
    
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            result.push_back(left[i]);
            i++;
        } else {
            result.push_back(right[j]);
            j++;
        }
    }
    
    while (i < left.size()) {
        result.push_back(left[i]);
        i++;
    }
    
    while (j < right.size()) {
        result.push_back(right[j]);
        j++;
    }
    
    return result;
}

std::list<int> PmergeMe::merge_list(std::list<int> &left, std::list<int> &right)
{
    std::list<int> result;
    std::list<int>::iterator left_it = left.begin();
    std::list<int>::iterator right_it = right.begin();
    
    while (left_it != left.end() && right_it != right.end()) {
        if (*left_it <= *right_it) {
            result.push_back(*left_it);
            ++left_it;
        } else {
            result.push_back(*right_it);
            ++right_it;
        }
    }
    
    while (left_it != left.end()) {
        result.push_back(*left_it);
        ++left_it;
    }
    
    while (right_it != right.end()) {
        result.push_back(*right_it);
        ++right_it;
    }
    
    return result;
}

std::vector<int> PmergeMe::merge_insert_sort_vector(std::vector<int> &arr)
{
    if (arr.size() <= 20) {
        insertion_sort_vector(arr, 0, arr.size() - 1);
        return arr;
    }
    
    size_t mid = arr.size() / 2;
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());
    
    left = merge_insert_sort_vector(left);
    right = merge_insert_sort_vector(right);
    
    return merge_vector(left, right);
}

std::list<int> PmergeMe::merge_insert_sort_list(std::list<int> &arr)
{
    if (arr.size() <= 20) {
        insertion_sort_list(arr);
        return arr;
    }
    
    std::list<int>::iterator mid_it = arr.begin();
    std::advance(mid_it, arr.size() / 2);
    
    std::list<int> left(arr.begin(), mid_it);
    std::list<int> right(mid_it, arr.end());
    
    left = merge_insert_sort_list(left);
    right = merge_insert_sort_list(right);
    
    return merge_list(left, right);
}

void PmergeMe::sort_vector()
{
    std::clock_t start = std::clock();
    m_vector = merge_insert_sort_vector(m_vector);
    std::clock_t end = std::clock();
    
    m_vector_time = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000000.0;
}

void PmergeMe::sort_list()
{
    std::clock_t start = std::clock();
    m_list = merge_insert_sort_list(m_list);
    std::clock_t end = std::clock();
    
    m_list_time = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000000.0;
}

void PmergeMe::print_before() const
{
    std::cout << "Before: ";
    
    size_t count = 0;
    for (std::vector<int>::const_iterator it = m_vector.begin(); it != m_vector.end(); ++it) {
        if (count >= 5) {
            std::cout << "[...]";
            break;
        }
        std::cout << *it;
        if (it + 1 != m_vector.end() && count < 4)
            std::cout << " ";
        count++;
    }
    std::cout << std::endl;
}

void PmergeMe::print_after() const
{
    std::cout << "After: ";
    
    size_t count = 0;
    for (std::vector<int>::const_iterator it = m_vector.begin(); it != m_vector.end(); ++it) {
        if (count >= 5) {
            std::cout << "[...]";
            break;
        }
        std::cout << *it;
        if (it + 1 != m_vector.end() && count < 4)
            std::cout << " ";
        count++;
    }
    std::cout << std::endl;
}

void PmergeMe::print_times() const
{
    std::cout << "Time to process a range of " << m_vector.size() 
              << " elements with std::vector : " 
              << std::fixed << std::setprecision(5) << m_vector_time << " us" << std::endl;
    
    std::cout << "Time to process a range of " << m_list.size() 
              << " elements with std::list : " 
              << std::fixed << std::setprecision(5) << m_list_time << " us" << std::endl;
}

void PmergeMe::run(int argc, char **argv)
{
    try {
        parse_input(argc, argv);
        print_before();
        sort_vector();
        sort_list();
        print_after();
        print_times();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}