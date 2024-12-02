#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter(void){

	return;
}

ScalarConverter::~ScalarConverter(void){

	return;
}

static bool isFloat(const std::string& string){

	std::string::const_iterator it = string.begin();
	bool decimalPoint = false;
	int minSize = 0;
	if(string.size()>0 && (string[0] == '-' || string[0] == '+')){
		it++;
		minSize++;
	}
	while(it != string.end()){
		if(*it == '.'){
			if(!decimalPoint) decimalPoint = true;
			else break;
		}else if(!std::isdigit(*it) && ((*it!='f') || it+1 != string.end() || !decimalPoint)){
			break;
		}
		++it;
	}
	return string.size()>minSize && it == string.end();
}




void	ScalarConverter::convert(std::string literal){

	char	c;
	int	toInt = 0;
	int	toFloat = 0;
	int	toDouble = 0;
	int i = 0;

	std::string	pseudo_literals[6] = {

		"-inff", "+inff", "nanf",
		"-inf", "+inf", "nan"

	};

	if (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])){
		
		std::cout << "char: " << literal[0] << std::endl;
		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(literal[0]) << ".0f"  << std::endl;
		std::cout << "double: " << static_cast<float>(literal[0]) << ".0"  << std::endl;
 	}
	if (isFloat(literal))
	{
		if (std::isprint(static_cast<char>(std::atof(literal.c_str()))))
			std::cout << "char: " << static_cast<char>(std::atof(literal.c_str()))<< std::endl;
		else
			std::cout << "char: " << "non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(std::atof(literal.c_str())) << std::endl;
		if (!std::atof(literal.c_str()) - static_cast<int>(std::atof(literal.c_str())))
			std::cout << "float: " << std::atof(literal.c_str()) << ".0f" << std::endl;
		else
			std::cout << "float: " << std::atof(literal.c_str()) << "f" << std::endl;
		std::cout << "double: " << std::atof(literal.c_str()) << std::endl;
	}
}


