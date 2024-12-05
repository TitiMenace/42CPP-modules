
#include "ScalarConverter.hpp"

bool	ScalarConverter::DecimalConverter(const std::string literal){

	long long value;
	int	sign = 1;
	long long out = 0;
	std::string::const_iterator	it = literal.begin();

	if (literal[0] == '-' || literal[0] == '+'){
		it++;
		if (literal[0] == '-')
			sign = -1;
	}
	while (it != literal.end()){
		if (!std::isdigit(*it))
			return false;
		out = out * 10 + (*it - '0');
		it++;
	}
	value = sign * out;
	if (value < 0 || value > 255)
			std::cout << "char : Impossible" << std::endl;
		else if (std::isprint(value))
			std::cout << "char : "<< static_cast<char>(value) << std::endl;
		else
			std::cout << "char : Non displayable" << std::endl;
	if (value > INT_MAX || value < INT_MIN)
		std::cout << "int : Impossible not in Range" << std::endl;
	else
		std::cout << "int : " << value << std::endl;
	std::cout << "float : " << static_cast<float>(value) << ".0f" << std::endl;
	std::cout << "double : " << static_cast<double>(value) << ".0" << std::endl;
	return true;	
}
