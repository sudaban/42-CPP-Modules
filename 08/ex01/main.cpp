#include "Span.h"
#include <stdlib.h>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));	
	Span sp = Span(100000);
	sp.addRandomNumbersToArray(-5000, 5000, 100000);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}