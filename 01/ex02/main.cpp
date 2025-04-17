#include <iostream>
#include <string>
#include <sstream>

enum Colors
{
    BLUE = 34,
    GREEN = 32,
    CYAN = 36,
    RED = 31,
    MAGENTA = 35,
    YELLOW = 33,
    WHITE = 37
};

void print(std::string text, Colors color)
{
    std::cout << "\033[" << color << "m" << text << "\033[0m" << std::endl;
}

std::string addressToString(void* ptr)
{
    std::ostringstream oss;
    oss << ptr;
    return oss.str();
}

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain;
    std::string& stringREF = brain;

    
    print("Memory address of brain: " + addressToString(&brain), CYAN);
    print("Memory address held by stringPTR: " + addressToString(stringPTR), CYAN);
    print("Memory address held by stringREF: " + addressToString(&stringREF), CYAN);

    print("Value of brain: " + brain, GREEN);
    print("Value pointed to by stringPTR: " + *stringPTR, GREEN);
    print("Value pointed to by stringREF: " + stringREF, GREEN);

    return 0;
}
