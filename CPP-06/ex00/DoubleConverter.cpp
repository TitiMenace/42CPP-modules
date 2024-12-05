
#include "ScalarConverter.hpp"

static bool	CheckDouble(const std::string literal){

	std::string::const_iterator	it = literal.begin();
	if (literal.size() < 3)
		return false;
	if (literal.size() > 0 && (literal[0] == '-' || literal[0] == '+')){
		it++;
	}
	while (std::isdigit(*it)){
		it++;
	}
	if (it != literal.end() && *it == '.' && std::isdigit(*(++it))){
		it++;
		while (std::isdigit(*it))
			it++;
		if (it == literal.end())
			return true;
	}
	return false;
}

static float	DoubleConversion(const std::string literal){
	
	int	sign = 1;
	size_t	real = 0;
	double	frac = 0.1;
	double	out = 0;
	std::string::const_iterator	it = literal.begin();
	if (literal[0] == '-' || literal[0] == '+'){
			it++;
		if (literal[0] == '-')
			sign = -1;
	}
	while (std::isdigit(*it)){
		real = real * 10 + (*it - '0');
		it++;
	}
	it++;
	while (std::isdigit(*it)){
		out = out + (frac * (*it - '0'));
		frac /= 10;
		it++;
	}
	out = sign * (real + out);
	return (out);
}



bool	ScalarConverter::DoubleConverter(const std::string literal){

	double	value;
	int		int_convert;

	if (CheckDouble(literal)){
	 
		value = DoubleConversion(literal);
		int_convert =  static_cast<int>(value);
		if (int_convert < 0 || int_convert > 255)
			std::cout << "char : Impossible" << std::endl;
		else if (std::isprint(int_convert))
			std::cout << "char : "<< static_cast<char>(int_convert) << std::endl;
		else
			std::cout << "char : Non displayable" << std::endl;
		if (value > INT_MAX || value < INT_MIN)
			std::cout << "int : Impossible not in Range" << std::endl;
		else
			std::cout << "int : " << int_convert << std::endl;
		std::cout << "float : " << static_cast<float>(value) << "f" << std::endl;
		std::cout << "double : " << value << std::endl;
		return true;
	}
	else
		return false;
}
