
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

	if (CheckDouble(literal)){
	 	value = DoubleConversion(literal);
		std::cout << "char : Impossible" << std::endl;
		std::cout << "int : " << static_cast<int>(value) << std::endl;
		std::cout << "float : " << static_cast<float>(value) << "f" << std::endl;
		std::cout << "double : " << value << std::endl;
		return true;
	}
	else
		return false;
}
