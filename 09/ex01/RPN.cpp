#include "RPN.hpp"
#include <sstream>
#include <stdexcept>

RPN::RPN() {}
RPN::~RPN() {}

RPN& RPN::operator=(const RPN& other) 
{
	m_deque = other.m_deque;
    if (this != &other) {
	}
    return *this;
}

RPN::RPN(const RPN& other)
{
	operator=(other);
}

bool RPN::is_operator(char c) const {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool RPN::is_digit(char c) const {
    return (c >= '0' && c <= '9');
}

int RPN::perform_operation(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0)
                throw std::runtime_error("Error: division by zero");
            return a / b;
        default:
            throw std::runtime_error("Error: invalid operator");
    }
}

int RPN::calculate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token) {
        if (token.length() == 1 && is_digit(token[0])) {
            m_deque.push_back(token[0] - '0');
        }
        else if (token.length() == 1 && is_operator(token[0])) {
            if (m_deque.size() < 2)
                throw std::runtime_error("Error: insufficient operands");
            
            int b = m_deque.back();
            m_deque.pop_back();
            int a = m_deque.back();
            m_deque.pop_back();
            
            int result = perform_operation(a, b, token[0]);
            m_deque.push_back(result);
        }
        else {
            throw std::runtime_error("Error: invalid token");
        }
    }
    
    if (m_deque.size() != 1)
        throw std::runtime_error("Error: invalid expression");
    
    return m_deque.back();
}