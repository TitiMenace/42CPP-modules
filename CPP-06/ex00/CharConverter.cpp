#include "ScalarConverter.hpp"

bool	ScalarConverter::CharConverter(const std::string literal){

	if (literal.size() == 1 && std::isprint(literal[0])){
		std::cout << "char : " << literal[0] << std::endl;
		std::cout << "int : " << static_cast<int>(literal[0]) << std::endl;
		std::cout << "float : " << static_cast<float>(literal[0]) << ".0f" <<  std::endl;
		std::cout << "double : " << static_cast<double>(literal[0]) << ".0" << std::endl;
		return true;
	}
	return false;
}





