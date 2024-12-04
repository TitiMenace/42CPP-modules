#include "ScalarConverter.hpp"
#include <limits.h>
#include <cfloat>



int	main(void)
{

	std::cout << FLT_MAX << std::endl;

	std::cout << "Test 1 : 7\n";
	ScalarConverter::convert("7312321132.321321312321f");	
	std::cout << "Test 2 : 2342\n";
	ScalarConverter::convert("2342");	
	std::cout << "Test 3 : -231\n";
	ScalarConverter::convert("4324723987492834729321890984059384095803485");	
	std::cout << "Test 4 : caca.wddwf\n";
	ScalarConverter::convert("caca.wddw");	
	std::cout << "Test 5 : -.f\n";
	ScalarConverter::convert("-.f");
}
