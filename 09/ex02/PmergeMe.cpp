#include "PmergeMe.hpp"
#include <stdexcept>

PmergeMe::PmergeMe() : m_vector_time(0), m_list_time(0) {}

PmergeMe::PmergeMe(const PmergeMe& other) : m_vector_time(0), m_list_time(0)
{
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        m_vector = other.m_vector;
        m_list = other.m_list;
        m_vector_time = other.m_vector_time;
        m_list_time = other.m_list_time;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::is_valid_number(const std::string& str) const
{
    if (str.empty())
        return false;
    
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    
    std::istringstream iss(str);
    long num;
    iss >> num;
    
    if (num < 0 || num > std::numeric_limits<int>::max())
        return false;
    
    return true;
}

void PmergeMe::parse_input(int argc, char** argv)
{
    for (int i = 1; i < argc; i++)
    {
        std::string arg(argv[i]);
        
        if (!is_valid_number(arg))
            throw std::runtime_error(ERR_NOT_POSITIVE_INT);
        
        int num = std::atoi(arg.c_str());
        m_vector.push_back(num);
        m_list.push_back(num);
    }
    
    if (m_vector.empty())
        throw std::runtime_error(ERR_EMPTY_SEQUENCE);
}

size_t PmergeMe::get_jacobsthal_number(size_t n) const
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    
    size_t prev_2 = 0;
    size_t prev_1 = 1;
    size_t current = 0;
    
    for (size_t i = 2; i <= n; i++)
    {
        current = prev_1 + 2 * prev_2;
        prev_2 = prev_1;
        prev_1 = current;
    }
    
    return current;
}

std::vector<size_t> PmergeMe::generate_jacobsthal_sequence(size_t len) const
{
    std::vector<size_t> sequence;
    size_t index = 3;
    
    while (true)
    {
        size_t jacob = get_jacobsthal_number(index);
        if (jacob >= len)
            break;
        sequence.push_back(jacob);
        index++;
    }
    
    return sequence;
}

int PmergeMe::binary_search_vector(const std::vector<int>& arr, int value, int left, int right) const
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == value)
            return mid;
        else if (arr[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return left;
}

void PmergeMe::ford_johnson_sort_vector(std::vector<int>& arr)
{
    size_t n = arr.size();
    
    if (n <= 1)
        return;
    
    std::vector<std::pair<int, int> > pairs;
    int straggler = -1;
    bool has_straggler = false;
    
    for (size_t i = 0; i + 1 < n; i += 2)
    {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }
    
    if (n % 2 == 1)
    {
        straggler = arr[n - 1];
        has_straggler = true;
    }
    
    if (pairs.size() > 1)
    {
        std::vector<int> main_chain;
        for (size_t i = 0; i < pairs.size(); i++)
            main_chain.push_back(pairs[i].first);
        
        ford_johnson_sort_vector(main_chain);
        
        for (size_t i = 0; i < pairs.size(); i++)
        {
            for (size_t j = 0; j < pairs.size(); j++)
            {
                if (pairs[j].first == main_chain[i])
                {
                    std::pair<int, int> temp = pairs[i];
                    pairs[i] = pairs[j];
                    pairs[j] = temp;
                    break;
                }
            }
        }
    }
    
    std::vector<int> sorted;
    std::vector<int> pend;
    
    if (!pairs.empty())
    {
        sorted.push_back(pairs[0].second);
        sorted.push_back(pairs[0].first);
        
        for (size_t i = 1; i < pairs.size(); i++)
        {
            sorted.push_back(pairs[i].first);
            pend.push_back(pairs[i].second);
        }
    }
    
    std::vector<size_t> jacob_sequence = generate_jacobsthal_sequence(pend.size() + 1);
    std::vector<bool> inserted(pend.size(), false);
    
    for (size_t i = 0; i < jacob_sequence.size(); i++)
    {
        size_t jacob = jacob_sequence[i];
        
        if (jacob <= pend.size())
        {
            for (size_t j = jacob; j > 0; j--)
            {
                size_t idx = j - 1;
                
                if (idx < pend.size() && !inserted[idx])
                {
                    int pos = binary_search_vector(sorted, pend[idx], 0, sorted.size() - 1);
                    sorted.insert(sorted.begin() + pos, pend[idx]);
                    inserted[idx] = true;
                }
            }
        }
    }
    
    for (size_t i = 0; i < pend.size(); i++)
    {
        if (!inserted[i])
        {
            int pos = binary_search_vector(sorted, pend[i], 0, sorted.size() - 1);
            sorted.insert(sorted.begin() + pos, pend[i]);
        }
    }
    
    if (has_straggler)
    {
        int pos = binary_search_vector(sorted, straggler, 0, sorted.size() - 1);
        sorted.insert(sorted.begin() + pos, straggler);
    }
    
    arr = sorted;
}

void PmergeMe::ford_johnson_sort_list(std::list<int>& arr)
{
    size_t n = arr.size();
    
    if (n <= 1)
        return;
    
    std::list<std::pair<int, int> > pairs;
    int straggler = -1;
    bool has_straggler = false;
    
    std::list<int>::iterator it = arr.begin();
    while (it != arr.end())
    {
        int first = *it;
        ++it;
        
        if (it != arr.end())
        {
            int second = *it;
            ++it;
            
            if (first > second)
                pairs.push_back(std::make_pair(first, second));
            else
                pairs.push_back(std::make_pair(second, first));
        }
        else
        {
            straggler = first;
            has_straggler = true;
        }
    }
    
    if (pairs.size() > 1)
    {
        std::list<int> main_chain;
        for (std::list<std::pair<int, int> >::iterator pit = pairs.begin(); pit != pairs.end(); ++pit)
            main_chain.push_back(pit->first);
        
        ford_johnson_sort_list(main_chain);
        
        std::list<std::pair<int, int> > sorted_pairs;
        for (std::list<int>::iterator mit = main_chain.begin(); mit != main_chain.end(); ++mit)
        {
            for (std::list<std::pair<int, int> >::iterator pit = pairs.begin(); pit != pairs.end(); ++pit)
            {
                if (pit->first == *mit)
                {
                    sorted_pairs.push_back(*pit);
                    break;
                }
            }
        }
        pairs = sorted_pairs;
    }
    
    std::list<int> sorted;
    std::list<int> pend;
    
    if (!pairs.empty())
    {
        std::list<std::pair<int, int> >::iterator pit = pairs.begin();
        sorted.push_back(pit->second);
        sorted.push_back(pit->first);
        ++pit;
        
        while (pit != pairs.end())
        {
            sorted.push_back(pit->first);
            pend.push_back(pit->second);
            ++pit;
        }
    }
    
    std::vector<size_t> jacob_sequence = generate_jacobsthal_sequence(pend.size() + 1);
    std::vector<bool> inserted(pend.size(), false);
    std::vector<int> pend_vec(pend.begin(), pend.end());
    
    for (size_t i = 0; i < jacob_sequence.size(); i++)
    {
        size_t jacob = jacob_sequence[i];
        
        if (jacob <= pend_vec.size())
        {
            for (size_t j = jacob; j > 0; j--)
            {
                size_t idx = j - 1;
                
                if (idx < pend_vec.size() && !inserted[idx])
                {
                    std::list<int>::iterator pos = sorted.begin();
                    while (pos != sorted.end() && *pos < pend_vec[idx])
                        ++pos;
                    
                    sorted.insert(pos, pend_vec[idx]);
                    inserted[idx] = true;
                }
            }
        }
    }
    
    for (size_t i = 0; i < pend_vec.size(); i++)
    {
        if (!inserted[i])
        {
            std::list<int>::iterator pos = sorted.begin();
            while (pos != sorted.end() && *pos < pend_vec[i])
                ++pos;
            
            sorted.insert(pos, pend_vec[i]);
        }
    }
    
    if (has_straggler)
    {
        std::list<int>::iterator pos = sorted.begin();
        while (pos != sorted.end() && *pos < straggler)
            ++pos;
        
        sorted.insert(pos, straggler);
    }
    
    arr = sorted;
}

void PmergeMe::sort_vector()
{
    std::clock_t start = std::clock();
    ford_johnson_sort_vector(m_vector);
    std::clock_t end = std::clock();
    
    m_vector_time = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000000.0; // microsecond
}

void PmergeMe::sort_list()
{
    std::clock_t start = std::clock();
    ford_johnson_sort_list(m_list);
    std::clock_t end = std::clock();
    
    m_list_time = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000000.0; // microsecond
}

void PmergeMe::print_before() const
{
    std::cout << "Before: ";
    
    size_t count = 0;
    for (std::vector<int>::const_iterator it = m_vector.begin(); it != m_vector.end(); ++it)
    {
        if (count >= 5)
        {
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
    for (std::vector<int>::const_iterator it = m_vector.begin(); it != m_vector.end(); ++it)
    {
        if (count >= 5)
        {
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

void PmergeMe::run(int argc, char** argv)
{
    try
    {
        parse_input(argc, argv);
        print_before();
        sort_vector();
        sort_list();
        print_after();
        print_times();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}