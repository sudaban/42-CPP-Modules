/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:40:40 by sdaban            #+#    #+#             */
/*   Updated: 2026/01/26 12:12:54 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>

#define ERR_EMPTY_VECTOR "Error: vector is empty"
#define ERR_INVALID_ARG "Error: invalid argument "

class PmergeMe 
{
private:
    std::vector<int> m_vector;
    std::list<int> m_list;
    double m_vector_time;
    double m_list_time;

    void parse_input(int argc, char **argv);
    bool is_valid_number(const std::string &str);
    
    void sort_vector();
    void sort_list();
    
    std::vector<int> merge_insert_sort_vector(std::vector<int> &arr);
    std::list<int> merge_insert_sort_list(std::list<int> &arr);
    
    void insertion_sort_vector(std::vector<int> &arr, int left, int right);
    void insertion_sort_list(std::list<int> &arr);
    
    std::vector<int> merge_vector(std::vector<int> &left, std::vector<int> &right);
    std::list<int> merge_list(std::list<int> &left, std::list<int> &right);
    
    void print_before() const;
    void print_after() const;
    void print_times() const;

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();
    
    void run(int argc, char **argv);
};

#endif // PMERGEME_HPP