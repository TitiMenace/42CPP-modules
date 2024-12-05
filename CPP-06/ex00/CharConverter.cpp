#include "ScalarConverter.hpp"

bool	ScalarConverter::CharConverter(const std::string literal){

	if (literal.size() == 3 && std::isprint(literal[1]) && literal[0] == '\'' && 
			literal[2] == '\''){
		std::cout << "char : " << literal[1] << std::endl;
		std::cout << "int : " << static_cast<int>(literal[1]) << std::endl;
		std::cout << "float : " << static_cast<float>(literal[1]) << ".0f" <<  std::endl;
		std::cout << "double : " << static_cast<double>(literal[1]) << ".0" << std::endl;
		return true;
	}
	return false;
}





