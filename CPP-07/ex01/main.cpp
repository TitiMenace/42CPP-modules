#include "template.hpp"


int main() {
	
	int int_array[] = {1, 2, 3, 4, 5};
	std::string str_array[] = {"one", "two", "three", "four", "five"};

	std::cout << "int_array: ";
	iter(int_array, 5, print);
	std::cout << std::endl;

	std::cout << "str_array: ";
	iter(str_array, 5, print);
	return 0;
}
