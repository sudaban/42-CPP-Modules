#include "Span.h"
#include <algorithm>
#include <climits>
#include <cstdlib>

const char* Span::SpanFullException::what() const throw()
{
	return "Span is full";
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
	return "Not enough numbers to find a span";
}

Span::Span(unsigned int n) : m_capacity(n)
{
	m_array.reserve(m_capacity);
}

Span& Span::operator=(const Span& s)
{
	if (this != &s)
	{
		m_capacity = s.m_capacity;
		m_array = s.m_array;
	}
	return *this;
}

Span::Span(const Span& s) : m_array(s.m_array), m_capacity(s.m_capacity) {}

Span::~Span() {}

void Span::addNumber(int num)
{
	if (m_array.size() >= m_capacity)
		throw SpanFullException();
	m_array.push_back(num);
}

int Span::shortestSpan()
{
	if (m_array.size() < 2)
		throw NotEnoughNumbersException();

	std::vector<int> sorted(m_array);
	std::sort(sorted.begin(), sorted.end());
	
	int minimum = INT_MAX;
	std::vector<int>::iterator it = sorted.begin();
	
	while (it != sorted.end() - 1)
	{
		int span = *(it + 1) - *it;
		if (span < minimum)
			minimum = span;
		++it;
	}
	return minimum;
}

int Span::longestSpan()
{
	if (m_array.size() < 2)
		throw NotEnoughNumbersException();

	std::vector<int>::iterator minIt = std::min_element(m_array.begin(), m_array.end());
	std::vector<int>::iterator maxIt = std::max_element(m_array.begin(), m_array.end());
	
	return *maxIt - *minIt;
}

void Span::addRandomNumbersToArray(int min, int max, size_t loop_count)
{
	if (m_array.size() + loop_count > m_capacity)
		throw SpanFullException();

	for (size_t i = 0; i < loop_count; ++i)
	{
		int num = rand() % (max - min + 1) + min;
		m_array.push_back(num);
	}
}