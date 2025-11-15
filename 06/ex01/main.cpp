#include <iostream>
#include <iomanip>
#include <string>
#include "Serializer.h"
#include "Data.h"

// ANSI color codes for terminals
static const char* COLOR_RESET = "\033[0m";
static const char* COLOR_BOLD = "\033[1m";
static const char* COLOR_CYAN = "\033[36m";
static const char* COLOR_GREEN = "\033[32m";
static const char* COLOR_YELLOW = "\033[33m";
static const char* COLOR_RED = "\033[31m";

static void print_data(const char* title, const Data* d) {
	std::cout << COLOR_CYAN << title << COLOR_RESET << std::endl;
	std::cout << std::setw(14) << std::left << "  Address:" << d << std::endl;
	std::cout << std::setw(14) << std::left << "  int_value:" << d->int_value << std::endl;
	std::cout << std::setw(14) << std::left << "  double_value:" << d->double_value << std::endl;
	std::cout << std::setw(14) << std::left << "  string_value:" << d->string_value << std::endl;
	std::cout << std::setw(14) << std::left << "  char_value:" << d->char_value << std::endl;
}

int main() {
	Data* original_data = new Data(42, 3.14159, "Hello World!", 'A');

	std::cout << COLOR_BOLD << "=== Serialization Test ===" << COLOR_RESET << std::endl << std::endl;

	print_data("Original Data:", original_data);
	std::cout << std::endl;

	// Serialize
	uintptr_t serialized_ptr = Serializer::serialize(original_data);
	std::cout << COLOR_YELLOW << "  Serialized pointer:" << COLOR_RESET << " 0x" 
		<< std::hex << serialized_ptr << std::dec << std::endl << std::endl;

	// Deserialize
	Data* deserialized_data = Serializer::deserialize(serialized_ptr);
	print_data("Deserialized Data:", deserialized_data);
	std::cout << std::endl;

	// Verification
	bool equal = (original_data == deserialized_data);
	std::cout << COLOR_BOLD << "=== Verification ===" << COLOR_RESET << std::endl;
	if (equal) {
		std::cout << COLOR_GREEN << "  SUCCESS: pointers match." << COLOR_RESET << std::endl;
	} else {
		std::cout << COLOR_RED << "  FAILURE: pointers do not match." << COLOR_RESET << std::endl;
	}

	// Second test (stack object)
	std::cout << std::endl << COLOR_BOLD << "=== Second Test (stack object) ===" << COLOR_RESET << std::endl;
	Data second_data(-123, -45.67, "Another test", 'Z');
	Data* second_ptr = &second_data;
	print_data("Second Data (before):", second_ptr);
	uintptr_t second_serialized = Serializer::serialize(second_ptr);
	Data* second_deserialized = Serializer::deserialize(second_serialized);
	print_data("Second Data (after):", second_deserialized);
	std::cout << std::endl;
	std::cout << "  Result: " << ((second_ptr == second_deserialized) ? (std::string(COLOR_GREEN) + "SUCCESS" + COLOR_RESET)
		: (std::string(COLOR_RED) + "FAILURE" + COLOR_RESET)) << std::endl;

	delete original_data;
	return 0;
}