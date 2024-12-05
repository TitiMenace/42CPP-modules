#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void){

	return;
}

ScalarConverter::~ScalarConverter(void){

	return;
}


static void	PseudoLiterals(size_t i){

	switch(i){
	
		case 1:
			std::cout << "char : Impossible" << std::endl;
			std::cout << "int : Impossible" << std::endl;
			std::cout << "float :-inff" << std::endl;
			std::cout << "double : -inf" << std::endl;
			break;
		case 2:
			std::cout << "char : Impossible" << std::endl;
			std::cout << "int : Impossible" << std::endl;
			std::cout << "float :+inff" << std::endl;
			std::cout << "double : +inf" << std::endl;
			break;
		case 3:
			std::cout << "char : Impossible" << std::endl;
			std::cout << "int : Impossible" << std::endl;
			std::cout << "float : nanf" << std::endl;
			std::cout << "double : nan" << std::endl;
			break;
	}
}

void	ScalarConverter::convert(std::string literal){
	
	size_t	i = 0;

	std::string	pseudo_literals[6] = {

		"-inff", "+inff", "nanf",
		"-inf", "+inf", "nan"
	};
	for (; literal != pseudo_literals[i] && i < 6; i++){}
	if (i <= 5){
		i = i / 2 + (i % 2);
		PseudoLiterals(i);
		return;
	}
	if (CharConverter(literal) || FloatConverter(literal) || DoubleConverter(literal) || 
			DecimalConverter(literal))
		return ;

}
	

