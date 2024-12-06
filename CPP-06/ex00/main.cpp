#include "ScalarConverter.hpp"
#include <limits.h>
#include <cfloat>



int	main(int ac, char **av)
{
	std::string value;

	if (ac != 2)
		return 1;
	else {
		value = av[1];
	//	std::cout << "Test 1 : " << value << std::endl;
		ScalarConverter::convert(value);
	}
	return 0;
}
