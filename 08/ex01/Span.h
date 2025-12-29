#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <vector>

class Span
{
private:
	std::vector<int> m_array;
	unsigned int m_capacity;
public:
	Span(unsigned int n);
	Span(const Span& s);
	Span& operator=(const Span& s);
	~Span();

	void addNumber(int num);
	int shortestSpan();
	int longestSpan();

	void addRandomNumbersToArray(int min, int max, size_t loop_count);

	class SpanFullException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	
	class NotEnoughNumbersException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};


#endif