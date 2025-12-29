#include "Span.h"
#include <stdlib.h>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));


    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "[TEST 1] shortest = " << sp.shortestSpan() << std::endl;
        std::cout << "[TEST 1] longest  = " << sp.longestSpan() << std::endl;
    }

    {
        Span sp(1000);
        sp.addRandomNumbersToArray(-100, 100, 1000);

        std::cout << "[TEST 2] shortest = " << sp.shortestSpan() << std::endl;
        std::cout << "[TEST 2] longest  = " << sp.longestSpan() << std::endl;
    }

    {
        try
        {
            Span sp(2);
            sp.addNumber(42);
            sp.shortestSpan(); //should throw
        }
        catch (const std::exception &e)
        {
            std::cout << "[TEST 3] exception = " << e.what() << std::endl;
        }
    }

    {
        try
        {
            Span sp(3);
            sp.addNumber(1);
            sp.addNumber(2);
            sp.addNumber(3);
            sp.addRandomNumbersToArray(0, 10, 1); //should throw
        }
        catch (const std::exception &e)
        {
            std::cout << "[TEST 4] exception = " << e.what() << std::endl;
        }
    }

    return 0;
}
