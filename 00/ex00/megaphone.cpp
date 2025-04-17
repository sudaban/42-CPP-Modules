#include <iostream>
#include <string>

std::string to_upper(std::string text)
{
    for (size_t i = 0; i < text.length(); ++i)
        text[i] = toupper(text[i]);
    return text;
}

int main(int argc, char const *argv[])
{
	(void)argv;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else {
		int i = 1;
		while (i < argc)
			std::cout << to_upper(argv[i]) , i++;
	}
	return 0;
}
