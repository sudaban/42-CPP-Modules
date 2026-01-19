/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdaban <sdaban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:26:18 by sdaban            #+#    #+#             */
/*   Updated: 2026/01/19 19:05:20 by sdaban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
#define RPN_H

#include <string>
#include <deque>

class RPN {
private:
    std::deque<int> m_deque;
    
    bool is_operator(char c) const;
    bool is_digit(char c) const;
    int perform_operation(int a, int b, char op);
    
public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
    
    int calculate(const std::string& expression);
};

#endif // RPN_H