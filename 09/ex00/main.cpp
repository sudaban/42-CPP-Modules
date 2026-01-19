#include "BitcoinExchange.h"
#include <iostream>

#define DB_FILE "data.csv"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange btc;

    if (!btc.load_database(DB_FILE))
    {
        std::cout << "Error: could not load database." << std::endl;
        return 1;
    }

    btc.process_input(argv[1]);
    return 0;
}
