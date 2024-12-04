#include "ScalarConverter.hpp"


static bool	CheckFloat(const std::string literal){

	std::string::const_iterator	it = literal.begin();
	if (literal.size() < 4)
		return false;
	if (literal.size() > 0 && (literal[0] == '-' || literal[0] == '+')){
		it++;
	}
	while (std::isdigit(*it)){
		it++;
	}
	if (it != literal.end() && *it == '.' && std::isdigit(*(++it))){
		it++;
		while (std::isdigit(*it)){
			it++;
		}
		if (*it == 'f' && ++it == literal.end()){
			return true;
		}
	}
	return false;
}

static float	FloatConversion(const std::string literal){
	
	int	sign = 1;
	size_t	real = 0;
	float 	frac = 0.1;
	float	out = 0;
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



bool	ScalarConverter::FloatConverter(const std::string literal){

	float	value;

	if (CheckFloat(literal)){
	 	value = FloatConversion(literal);
		std::cout << "char : Impossible" << std::endl;
		std::cout << "int : " << static_cast<int>(value) << std::endl;
		std::cout << "float : " << value << "f" << std::endl;
		std::cout << "double : " << static_cast<double>(value) << std::endl;
		return true;
	}
	else
		return false;
}
