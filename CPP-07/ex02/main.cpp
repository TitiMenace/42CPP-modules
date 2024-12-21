#include "Array.hpp"
#include <iostream>
#include <string>
#include <sstream>

int main(void) {
	Array<int> intArray(5);
	Array<std::string> stringArray(5);
	for (int i = 0; i < intArray.size(); i++)
		intArray[i] = i;
	for (int i = 0; i < stringArray.size(); i++)
	{
		std::ostringstream convert;
		convert << i;
		stringArray[i] = convert.str();
	}
	std::cout << "intArray: ";
	for (int i = 0; i < intArray.size(); i++)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;
	std::cout << "stringArray: ";
	for (int i = 0; i < stringArray.size(); i++)
		std::cout << stringArray[i] << " ";
	std::cout << std::endl;
	try {
		std::cout << "intArray[5]: " << intArray[5] << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}
