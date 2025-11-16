#include "ScalarConverter.h"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <literal_value>" << std::endl;
		return 1;
	}
	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch (const ScalarConverter::ErrorException& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}