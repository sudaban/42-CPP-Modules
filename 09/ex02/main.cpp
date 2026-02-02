#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: no arguments provided" << std::endl;
        return 1;
    }
    
    PmergeMe sorter;
    sorter.run(argc, argv);
    
    return 0;
}